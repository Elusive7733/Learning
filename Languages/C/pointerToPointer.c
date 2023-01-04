#include <stdio.h>

void main()
{
	int a;
	printf("Enter a\n");
	scanf("%d", &a);
	int *p = &a;
	int **p1;
	int ***p2;
	int ****p3;
	int *****p4;
	p1 = &p;
	p2 = &p1;
	p3 = &p2;
	p4 = &p3;
	*****p4 += 5;

	printf("Address of a %d\n", &a);
	printf("Address of *p %d\n", &p);
	printf("Address of **p1 %d\n", &p1);
	printf("Address of ***p2 %d\n", &p2);
	printf("Address of ****p3 %d\n", &p3);
	printf("Address of *****p4 %d\n", &p4);

	printf("value of a %d\n", a);
	printf("value of *p %d\n", p);
	printf("value of **p1 %d\n", p1);
	printf("value of ***p2 %d\n", p2);
	printf("value of ****p3 %d\n", p3);
	printf("value of *****p4 %d\n", p4);
}
