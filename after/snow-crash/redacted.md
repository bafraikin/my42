
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

