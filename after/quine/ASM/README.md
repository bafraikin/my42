# DR QUINE
https://fr.wikipedia.org/wiki/Quine_(informatique)

Le but du projet est de realiser plusieurs programmes qui output leur propre code source ou qui sont capable de s'autoreproduire en suivant differentes contraintes.

## ASM CHEATSHEET
### Registres

16 registres pour les entiers qui ont une largeur de 64 bits

|R0  |R1  |R2  |R3  |R4  |R5  |R6  |R7  |R8  |R9  |R10 |R11 |R12 |R13 |R14 |R15|
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | - |
|RAX |RCX |RDX |RBX |RSP |RBP |RSI |RDI

Les 32 bits les plus bas de chaque registre peuvent etre eux-memes etre traités comme des registres en utilisant ces noms :

|R0D |R1D |R2D |R3D |R4D |R5D |R6D |R7D |R8D |R9D |R10D|R11D|R12D|R13D|R14D|R15D|
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
|EAX |ECX |EDX |EBX |ESP |EBP |ESI |EDI

Les 16 bits les plus bas de chaque registre peuvent etre eux-memes etre traités comme des registres en utilisant ces noms :

|R0W |R1W |R2W |R3W |R4W |R5W |R6W |R7W |R8W |R9W |R10W|R11W|R12W|R13W|R14W|R15W|
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
|AX  |CX  |DX  |BX  |SP  |BP  |SI  |DI

Les bits 15 a 6 des registres R0 a R3 sont nommées :

AH CH DH BH

On compte aussi 16 registres XMMM qui font 128 bits nommées :

XMM0 ... XMM15

#### Ordre des registres

Lors de l'appel d'une fonction les registres sont appelés dans l'ordre suivant

rdi, rsi, rdx, rcx, r8, r9



#### Sources

https://cs.lmu.edu/~ray/notes/nasmtutorial/
