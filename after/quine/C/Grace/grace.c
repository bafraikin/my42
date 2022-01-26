#include <stdlib.h>

#define start main
//commentaire
#define A "#include <stdio.h>%c#include <stdlib.h>%c%c#define start main%c//commentaire%c#define A %c%s%c%c#define print(a) (fprintf((fopen(%cGrace_kid.c%c, %cw%c)),(a),10,10,10,10,10,34,(a),34,10,34,34,34,34,10,10,10,10,10))%c%cvoid start() {%cprint(A);%c}%c"
#define print(a) (fprintf((fopen("Grace_kid.c", "w")),(a),10,10,10,10,10,34,(a),34,10,34,34,34,34,10,10,10,10,10))

void start() {
print(A);
}
