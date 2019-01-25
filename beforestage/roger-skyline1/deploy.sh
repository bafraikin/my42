#!/bin/bash
ip=ping google.com | arp -a | grep "?" |  awk 'NR==1' | cut -d '(' -f 2 | cut -d ')' -f 1


ssh root@$ip

apt-get install -y sudo apache2 ufw fail2ban portsentry
#user with sudo
adduser $coucou sudo
#dhcp
/etc/network/interfaces < string="auto enp0s3
iface enp0s3 inet static
	address $1
	netmask 255.255.255.252
	gateway 10.11.254.254
"
/etc/init.d/network restart
sed -i 's/22/3022/' /etc/ssh/sshd_config
sed -i 's/#PermitRootLogin yes/PermitRootLogin no/'

ufw allow 3022/tcp
ufw allow 443/tcp
ufw deny ssh
ufw deny 80/tcp

