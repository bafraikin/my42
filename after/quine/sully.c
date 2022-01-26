#include<stdio.h>
#include<stdlib.h>

int main() {
	char name[30000];
	char compilation[40000];
	char *a="#include<stdio.h>%c#include<stdlib.h>%c%cint main() {%c%cchar name[30000];%c%cchar compilation[40000];%c%cchar *a=%c%s%c;%c%cint i=%d;%c%c%cif (i > 0) {%c%c%csprintf(name, %cSully_%cd.c%c, --i);%c%c%cFILE *file=fopen(name, %cw%c);%c%c%cfprintf(file,a,10,10,10,10,9,10,9,10,9,34,a,34,10,9,i,10,10,9,10,9,9,34,37,34,10,9,9,34,34,10,9,9,10,9,9,10,9,9,34,37,37,37,34,10,9,9,10,9,10,10);%c%c%cfclose(file);%c%c%csprintf(compilation, %cgcc -o Sully_%cd %cs && ./Sully_%cd%c,i,name,i);%c%c%csystem(compilation);%c%c}%c}%c";
	int i=20;

	if (i > 0) {
		sprintf(name, "Sully_%d.c", --i);
		FILE *file=fopen(name, "w");
		fprintf(file,a,10,10,10,10,9,10,9,10,9,34,a,34,10,9,i,10,10,9,10,9,9,34,37,34,10,9,9,34,34,10,9,9,10,9,9,10,9,9,34,37,37,37,34,10,9,9,10,9,10,10);
		fclose(file);
		sprintf(compilation, "gcc -o Sully_%d %s && ./Sully_%d",i,name,i);
		system(compilation);
	}
}
