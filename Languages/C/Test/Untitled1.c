#include <stdio.h>

int fact(int x, int count)
{
	count--;
	if(x == 1 || x == 0)
	{
		return 1;
	}
	else
	{
		if(count > 1)
		{
			x *= count;
			fact(x, count);
		}
	}
}
void main()
{
	int n, count;
	printf("Enter N\n");
	scanf("%d", &n);
	count = n;
	printf("Factorial of %d is = %d", n, fact(n, count));
}
