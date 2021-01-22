#include <stdio.h>

expo(int x, int n)
{
	static int ans = 1;
	if(n >= 1)
	{
		ans *= x;
		n--;
		expo(x, n);
	}
	return ans;
}

main()
{
	int x, n;
	printf("Enter number\n");
	scanf("%d", &x);
	printf("Enter power\n");
	scanf("%d", &n);
	printf("Ans = %d" ,expo(x, n));
}
