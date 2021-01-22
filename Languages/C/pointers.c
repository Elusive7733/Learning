#include <stdio.h>

void point(int *a, int *b, int *c)
{
	*a += 5;
	*b = *b * *b;
	*c += *a + *b;
}

main()
{
	int a, b, c;
	printf("Enter a\n");
	scanf("%d", &a);
	printf("Enter b\n");
	scanf("%d", &b);
	printf("Enter c\n");
	scanf("%d", &c);
	point(&a, &b, &c);
	printf("a = %d\nb = %d\nc = %d", a, b, c);
}

