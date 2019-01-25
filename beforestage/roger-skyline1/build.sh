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

whoami=$(whoami)
vbox=/sgoinfre/goinfre/Perso/$whoami/roger
vbox_name=$vbox/$name
wrong_dir="/Users/$whoami/VirtualBox Vms"
iso=/sgoinfre/goinfre/ISO/Debian/debian-9.6.0-i386-DVD-1.iso
iso2=/sgoinfre/goinfre/ISO/Debian/debian-9.6.0-i386-DVD-2.iso
iso3=/sgoinfre/goinfre/ISO/Debian/debian-9.6.0-i386-DVD-3.iso

VBoxManage createvm --name "$name" --ostype Debian_64 --register
VBoxManage modifyvm "$name" --memory 1024 --acpi on --nic1 bridged --nictype1 82540EM --bridgeadapter1 en0 --vram 160

mv "$wrong_dir/$name" $vbox
ln -s $vbox_name "$wrong_dir"/$dir

VBoxManage createhd --filename $vbox_name/$name.vdi --size 8000
VBoxManage storagectl $name --name "SATA Controller" --add sata --controller IntelAHCI
VBoxManage storageattach $name --storagectl "SATA Controller" --port 0 --device 0 \
	--type hdd --medium $vbox_name/$name.vdi
VBoxManage storagectl "$name" --name "IDE Controller" --add ide --controller PIIX4
VBoxManage storageattach "$name" --storagectl "IDE Controller" --port 0 --device 0 --type dvddrive --medium $iso
cp preseed.cfg $vbox_name/preseed.cfg

VBoxManage unattended install $name \
	--iso=$iso \
	 --script-template=$vbox_name/preseed.cfg \
	--extra-install-kernel-parameters="auto=true preseed/file=$vbox_name/preseed.cfg  priority=critical quiet splash noprompt noshell automatic-ubiquity debian-installer/locale=en_US keyboard-configuration/layoutcode=us languagechooser/language-name=English localechooser/supported-locales=en_US.UTF-8 countrychooser/shortlist=US --" \
	--user=$name --full-user-name=$name --password $name \
		--install-additions --time-zone=CET


	# --auxiliary-base-path=$vbox_name/preseed.cfg \

#VBoxManage starvm $(echo $uuid | grep "Using" | cut -d "(" -f 2 | cut -d ")" -f 1)
