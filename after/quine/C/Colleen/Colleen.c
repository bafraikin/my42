#include<stdio.h>

void une_fonction(){
	char b = 1;
	b++;
}
/*
	un commentaire en dehors de la fonction
*/

int main(){

/*
	un commentaire dans la fonction main
*/
	une_fonction();

char*a="#include<stdio.h>%c%cvoid une_fonction(){%c%cchar b = 1;%c%cb++;%c}%c/*%c%cun commentaire en dehors de la fonction%c*/%c%cint main(){%c%c/*%c%cun commentaire dans la fonction main%c*/%c%cune_fonction();%c%cchar*a=%c%s%c;%cprintf(a,10,10,10,9,10,9,10,10,10,9,10,10,10,10,10,10,9,10,10,9,10,10,34,a,34,10,10,10);%c}%c";
printf(a,10,10,10,9,10,9,10,10,10,9,10,10,10,10,10,10,9,10,10,9,10,10,34,a,34,10,10,10);
}
