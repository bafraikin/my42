#include <stdlib.h>


int main(int argc, char *argv[])
{
	int *a;
	int i;
	int b;

	i = 2;
	a = &i; 
	b = a - (int*)NULL;
	return 0;
}
