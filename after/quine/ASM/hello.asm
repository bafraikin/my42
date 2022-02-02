          global    main
          extern    printf

          section   .text
main:    
          mov       rdi, message            ; address of string to output
          mov       rsi, message           ; address of string to output
          xor       rax, rax
          call      printf
          ret

message:  
          db        "Hello, World %s", 0      ; note the newline at the end
