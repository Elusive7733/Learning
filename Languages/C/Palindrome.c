#include <stdio.h>

int main()
{
	int temp, sum = 0, num, digit, count=0;

	printf("Enter Number\n");
	scanf("%d", &num);

	temp = num;

	while(num > 0)
	{
		digit = num % 10;
		sum  = sum*10 + digit;
		num /= 10;
	}

	if (sum == temp)
	{
		printf("It's a palindrome number");
	}
	else
	{
		printf("Not a palindrome number");
	}
	return 0;
}
