#include <stdio.h>

void main()
{
	int i, a, ar[4], sum = 0;
	printf("Enter a\n");
	scanf("%d", &a);
	char *p = &a;
	int *p1;
	p1 = (int*)p;	//type casting int ki type char main
	printf("size of int = %d\n", sizeof(int));
	for(i = 0; i < 4; i++)
	{
		printf("decimal value at byte no %c == %c\t\t\t(converted from  binary)\n", (p1+i), *(p1+i));
	}
}
