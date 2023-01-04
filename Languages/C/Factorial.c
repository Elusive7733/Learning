#include<stdio.h>

long fact(int n)
{
	static int i, count;
	count = n;
	while(count > 1)
	{
		count--;
		n *= count;
	}
	return n;
}

main()
{
	int x;
	printf("Enter x\n");
	scanf("%d", &x);
	printf("Factoral of %d = %ld", x, fact(x));
}
