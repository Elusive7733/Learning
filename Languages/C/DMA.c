#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x;
	int *p, *q;
	p = (int*) calloc(1,sizeof(int));
	q = (int*) calloc(1, sizeof(int));
	printf("first value of p = %d\n", *p);
	printf("first address of p = %d\n", p);
	printf("first value of q = %d\n", *q);
	printf("first address of q = %d\n", q);
	scanf(" %d", p);
	scanf(" %d", q);
	printf("second value of p = %d\n", *p);
	printf("second address of p = %d\n", p);
	printf("second value of q = %d\n", *q);
	printf("second address of q = %d\n", q);
	*p *= *q;
	*q -= *p;
	printf("third value of p = %d\n", *p);
	printf("third address of p = %d\n", p);
	printf("third value of q = %d\n", *q);
	printf("third address of q = %d\n", q);
}
