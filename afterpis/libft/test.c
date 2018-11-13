

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int x;
extern int end, edata;

void *stack_bottom;

char IS_IN_STACK(void *x) __attribute__((noinline));
char IS_IN_STACK(void *x) {
	void *stack_top = &stack_top;
	return x <= stack_bottom && x >= stack_top;
}

#define IS_STATIC(x) ((void*)(x) <= (void*)&end || (void*)(x) <= (void*)&edata)

void foo (void)
{
	int s;
	int *h = malloc (sizeof(int));

	printf ("x = %p, *s = %p, h = %p\n", &x, &s, h);
	// prints 0 1 0
	printf ("%d %d %d\n", IS_IN_STACK(&x), IS_IN_STACK(&s), IS_IN_STACK(h));
	//         // prints 1 0 0
	printf ("%d %d %d\n", IS_STATIC(&x), IS_STATIC(&s), IS_STATIC(h));
}

//
int main (int argc, char *argv[])
{
	int x;
	stack_bottom = &x;
	foo();
	return 0;
}
