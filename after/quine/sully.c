#include<stdio.h>

int main() {
	char name[40000];
	char *a="#include<stdio.h>%c%cint main() {%c%cchar name[40000];%c%cchar *a=%c%s%c;%c%cint i=%d;%c%c%cif (i > 0) {%c%c%csprintf(name, %cSully_%cd.c%c, --i);%c%c%cfprintf(fopen(name, %cw%c),a,10,10,10,9,10,9,34,a,34,10,9,i,10,10,9,10,9,9,34,37,34,10,9,9,34,34,10,9,10,10,10);%c%c}%c}%c";
	int i=5;

	if (i > 0) {
		sprintf(name, "Sully_%d.c", --i);
		fprintf(fopen(name, "w"),a,10,10,10,9,10,9,34,a,34,10,9,i,10,10,9,10,9,9,34,37,34,10,9,9,34,34,10,9,10,10,10);
	}
}
