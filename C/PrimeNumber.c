#include <stdio.h>

main()
{
	int x, num, count = 0, y = 0;
	printf("Enter num\n");
	scanf("%d", &num);
	for(x = 2; x < num; x++)
	{
		y = num % x ;
		
		if(y == 0)
		{
			count++ ;
		}
		
	}
	
	if (count != 0)
	{
	printf("The number is not a prime");
	}
	else
	{
		printf("The number is prime");
	}
	return 0;
}
