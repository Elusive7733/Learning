#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void main()
{
	int opt, N, i, sum, a, b, c;
	printf("What would you like to do:\n");
	printf("\n");
	printf("1- Find the sum of N natural numbers\n");
	printf("2- Find the factorial of a number\n");
	printf("3- Find the factorials of numbers from 1 - 20\n");
	printf("69- Secret\n");
	scanf("%d", &opt);

	switch (opt)
	{
		case 1 :
		{
			system("cls");
			printf("Enter N\n");
			scanf("%d", &N);
			for(i = 1 ; i <= N ; i++)
			{
				sum += i;
			}
			printf("Sum = %d", sum);
			break;
		}
		case 2 :
		{
			system("cls");
			printf("Enter Number\n");
			scanf("%d", &a);
			b = a;
			while (b > 1)
			{
				b--;
				a *= b;
			}
			printf ("%d", a);
			break;
		}
		case 3 :
		{
			system("cls");
			a = 1;
			c = 1;
			while (a < 20)
			{
				b = c;
				while (b > 1)
				{
					b--;
					c *= b;
				}
			printf ("%d\n", c);
			a++;
			b++;
			}
		break;
		}
		case 69:
		system("cls");
		printf("You really thought this program would have a Secret\n");
		for(i = 0; i < 5; i++)
		{
			sleep(1);
			printf("tcuh!\n");
		}
		sleep(3);
		printf("Well you were right\n\n\n\t\t\tIT DOES\n\t\t\tpls wait\n");
		sleep(5);
		for(i = 0; i < 100000; i++)
		{
			printf("Calcluating the survial of human race\n Currently = 0\n%d\n", i);
		}
		system("cls");
		printf("ligma\n");
		break;
		default : printf("Error 404"); break;
	}
}
