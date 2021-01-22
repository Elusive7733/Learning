#include <stdio.h>

void main()
{
	char alp;
	int i, j;
	printf("Enter Alphabet\n");
	scanf("%c", &alp);
	system("cls");

	for (i = 1 ; i <= 4 ; i++)
	{
		for (j = 1 ; j <= i ; j++)
		{
		printf("%c\t"  , alp);
		}
	alp++;
	printf ("\n");
	printf ("\n");
	}

	for (i = 4 ; i >= 1 ; i--)
	{
		for (j = 1 ; j <= i ; j++)
		{
		printf("%c\t"  , alp);
		}
	alp++;
	printf ("\n");
	printf ("\n");
	}
}
