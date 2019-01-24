#!/bin/bash

_DEBUG='on'

function DEBUG()
{
	 [ "$_DEBUG" == "on" ] &&  $@
}

name=""
if [ $# = 0 ]
then
	echo "give a name to your vm"
	read name
else
	name=$1
fi

echo $name

whoami=$(whoami)
vbox=/sgoinfre/goinfre/Perso/$(whoami)/roger
vbox_name=$vbox/$name
wrong_dir="/Users/$whoami/VirtualBox Vms"
iso=/sgoinfre/goinfre/ISO/Debian/debian-9.6.0-i386-DVD-1.iso

VBoxManage createvm --name "$name" --ostype Debian_64 --register
VBoxManage modifyvm "$name" --memory 1024 --acpi off --nic1 bridged --nictype1 82540EM --bridgeadapter1 en0 --vram 160

mv "$wrong_dir/$name" $vbox
ln -s $vbox_name "$wrong_dir"/$dir

VBoxManage createhd --filename $vbox_name/$name.vdi --size 8000
VBoxManage storagectl $name --name "SATA Controller" --add sata --controller IntelAHCI
VBoxManage storageattach $name --storagectl "SATA Controller" --port 0 --device 0 \
	--type hdd --medium $vbox_name/$name.vdi
#VBoxManage storagectl "$name" --name "IDE Controller" --add ide --controller PIIX4
#VBoxManage storageattach "$name" --storagectl "IDE Controller" --port 0 --device 0 --type dvddrive --medium $iso
uuid=$(VBoxManage unattended install $name \
	--iso=$iso \
	--user=$name --full-user-name=$name --password $name \
	--install-additions --time-zone=CET)

echo $uuid
