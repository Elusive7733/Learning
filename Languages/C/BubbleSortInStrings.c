#include <stdio.h>
#include <string.h>

void main()
{

	char *Names[] ={"Bilal","Areeba","Raheem","Danish","Zainab","Fatima"};
	char *temp;
	int i, j, x;
	printf("Enter No of Namess\n");
	scanf("%d", &x);
	Names[x] = (char *) calloc(x, sizeof(char));
	
	for (i = 0 ; i < x ; i++)
	{
		for (j = i+1 ; j < x ; j++)
		{
			if(strcmp(Names[i], Names[j]) > 0)
			{
				temp = Names[i];
				Names[i] = Names[j];
				Names[j] = temp;
			}
		}
	}
	
	for (i = 0 ; i < x ; i++)
	{
		printf("%s\n", *(Names+i));
	}

}
