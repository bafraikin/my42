global main
extern printf

section .text

;coucou Colleen
salut:
mov rdi, 0
inc rdi
ret

main:
mov rdi, message ; salut
mov rsi, message
mov rdx, 10
mov rcx, 34
xor rax, rax
call printf
ret

message:
db "global main%2$cextern printf%2$c%2$csection .text%2$c%2$c;coucou Colleen%2$csalut:%2$cmov rdi, 0%2$cinc rdi%2$cret%2$c%2$cmain:%2$cmov rdi, message ; salut%2$cmov rsi, message%2$cmov rdx, 10%2$cmov rcx, 34%2$cxor rax, rax%2$ccall printf%2$cret%2$c%2$cmessage:%2$cdb %3$c%1$s%3$c, 0%2$c", 0
