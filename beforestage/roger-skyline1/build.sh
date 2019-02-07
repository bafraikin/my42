#!/bin/bash

name=""
if [ $# = 0 ]
then
	echo "give a name to your vm"
	read name
else
	name=$1
fi

whoami=$(whoami)
vbox=/Users/bafraiki/VirtualBox\ VMs
vbox_name=$vbox/$name
iso=/sgoinfre/goinfre/ISO/Debian/debian-9.6.0-i386-DVD-1.iso
VBoxManage createvm --name "$name" --ostype Debian_64 --register
VBoxManage modifyvm "$name" --memory 1024 --acpi on --nic1 bridged --nictype1 82540EM --bridgeadapter1 en0 --vram 160
VBoxManage createhd --filename "$vbox_name/$name.vdi" --size 8000
VBoxManage storagectl $name --name "SATA Controller" --add sata --controller IntelAHCI
VBoxManage storageattach $name --storagectl "SATA Controller" --port 0 --device 0 \
	--type hdd --medium "$vbox_name/$name.vdi"
VBoxManage storagectl "$name" --name "IDE Controller" --add ide --controller PIIX4
VBoxManage storageattach "$name" --storagectl "IDE Controller" --port 0 --device 0 --type dvddrive --medium $iso
