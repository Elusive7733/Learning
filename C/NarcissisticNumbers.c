#include <stdio.h>
#include <math.h>

void main()
{
	int i, temp, number, sdig, ans = 0, digits = 0;  //sdig = single digit.
	
	printf("Enter Number\n");
	scanf("%d", &number);
	
	temp = number;
	
	while(number > 0)
	{
		number /= 10;
		digits++ ;
	}
	
	number = temp;
	
	for(i = 1; i <= digits; i++)
	{
		sdig = number%10 ; 
		number /= 10;
		ans += pow(sdig, digits);
	}
	
	if(ans == temp)
	{
		printf("%d is a Narcissistic/armstrong number", temp);
	}
	else
	{
		printf("%d is not a Narcissistic/armstrong number", temp);
	}
}
