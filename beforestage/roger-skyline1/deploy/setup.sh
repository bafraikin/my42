#!/bin/bash

ip="vide"

if [ $# = 0 ]
then
	echo "fuck off you bastard" && exit
elif [ $# = 1 ]
then
	echo "give me an ip please"
	read ip
else
	ip=$2
fi

#ip=$(ping google.com | arp -a | grep "?" |  awk 'NR==1' | cut -d '(' -f 2 | cut -d ')' -f 1)

cp $HOME/.ssh/id_rsa.pub authorized_keys
scp -r . $1@$ip:/home/$1
scp deploy.sh $1@$ip:/home/$1
ssh $1@$ip

