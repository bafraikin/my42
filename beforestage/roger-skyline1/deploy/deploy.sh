#!/bin/bash

#connect to root
apt-get install -y sudo apache2 ufw fail2ban portsentry mailutils postfix

if [ $# = 0 ]
then
	echo "you're a little piece of shit"
fi


hom=/home/$1


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
sed -i 's/#Port 22/Port 3022/' /etc/ssh/sshd_config
sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config
/etc/init.d/ssh restart

#firewall
ufw default deny incoming
ufw default allow outgoing
ufw allow in 3022/tcp
ufw allow 443/tcp
ufw deny in ssh
ufw deny 80/tcp
ufw enable

#fail2ban
mv $hom/custom.conf /etc/fail2ban/jail.d
mv $hom/jail.local /etc/fail2ban
mv $hom/http-ddos.conf /etc/fail2ban/filter.d
/etc/init.d/fail2ban restart

#portsentry
mv $hom/portsentry.conf /etc/portsentry
mv $hom/portsentry /etc/default
/etc/init.d/portsentry restart

mv $hom/crontab_dif.sh /root
cp $hom/crontab /root/past_cron
mv $hom/crontab /etc

sed -i 's/inet_interfaces.*$/inet_interfaces = loopback-only\n/'   /etc/postfix/main.cf
service postfix restart
hostname debian.fr


#ssl

mv $hom/sites-available/* /etc/apache2/sites-available/
mv $hom/ssl /etc/apache2/
a2enmod ssl
a2ensite default-ssl.conf
a2enmod rewrite
mv $hom/ports.conf /etc/apache2
/etc/init.d/apache2 restart
mv $hom/html/* /var/www/html
