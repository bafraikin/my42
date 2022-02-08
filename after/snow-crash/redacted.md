
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
