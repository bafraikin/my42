#!/bin/bash

#connect to root
apt-get install -y sudo apache2 ufw fail2ban portsentry

if [ $# = 0 ]
then
	echo "you're a little piece of shit"
fi

#user with sudo
adduser $1 sudo

#dhcp
sed -i 's/allow-hotplug/auto/' /etc/network/interfaces
sed -i 's/dhcp/static\n\taddress 10.11.8.150\n\tnetmask 255.255.255.252\n\tgateway 10.11.254.254/' /etc/network/interfaces
ip addr del $(ip addr)
/etc/init.d/networking restart

#ssh
mkdir /home/$1/.ssh
mv /home/$1/authorized_keys /home/$1/.ssh
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

fail2ban enable
jail.local

#reboot

