#!/bin/bash

if [ $# = 0 ]
then
	echo "you're a little piece of shit"
elif [ $# = 2 ]
then
	sudo rm -rf /var/www/html
	sudo cp -r html /var/www/html
	exit 0
fi

#connect to root
sed  -i 's/^.*cdrom.*$//' /etc/apt/sources.list
apt-get install -y sudo apache2 fail2ban portsentry mailutils postfix


hom=/home/$1/deploy

#user with sudo
adduser $1 sudo

#dhcp
sed -i 's/allow-hotplug/auto/' /etc/network/interfaces
sed -i 's/dhcp/static\n\taddress 10.11.8.150\n\tnetmask 255.255.255.252\n\tgateway 10.11.254.254/' /etc/network/interfaces
ip addr del $(ip addr)
/etc/init.d/networking restart

#ssh
mkdir /home/$1/.ssh
mv $hom/authorized_keys /home/$1/.ssh
sed -i 's/#Port 22/Port 42/' /etc/ssh/sshd_config
sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config
/etc/init.d/ssh restart

#firewall
mv $hom/iptables.up.rules /etc
mv $hom/iptables /etc/network/if-pre-up.d
/sbin/iptables-restore  /etc/iptables.up.rules

#fail2ban
mv $hom/custom.conf /etc/fail2ban/jail.d
mv $hom/jail.local /etc/fail2ban
mv $hom/http-ddos.conf /etc/fail2ban/filter.d
mv $hom/route.conf /etc/fail2ban/action.d
/etc/init.d/fail2ban restart

#portsentry
mv $hom/portsentry.conf /etc/portsentry
mv $hom/portsentry /etc/default
/etc/init.d/portsentry restart

mv $hom/crontab_dif.sh /root
chown root $hom/crontab
chgrp root $hom/crontab
cp $hom/crontab /root/past_cron
mv $hom/crontab /etc
sed -i 's/inet_interfaces.*$/inet_interfaces = loopback-only\n/'   /etc/postfix/main.cf
service postfix restart
hostname debian.fr


#ssl
mv $hom/sites-available/* /etc/apache2/sites-available/
mv $hom/ssl /etc/apache2/

a2dissite 000-default.conf
a2dissite default-ssl.conf
a2enmod ssl
a2ensite rs1.conf
a2ensite rs1-ssl.conf
a2enmod rewrite
mv $hom/ports.conf /etc/apache2
/etc/init.d/apache2 restart
rm -rf /var/www/html
cp -r $hom/html /var/www/html

rm -rf $hom/setup.sh $hom/sites-available

ip addr del $(ip addr | grep inet | grep 10.11 | awk 'NR == 1' | cut -d " " -f 6- | cut -d " " -f 1) dev enp0s3
