#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i, m, j, k;
	printf("Input: M = ");
	scanf("%d", &m);
	
	int *ar = (int *) calloc(m*m, sizeof(int));
	int *rev = (int *) calloc(m*m, sizeof(int));
	
	for(i = 0; i < m*m; i++)
	{
			scanf("%d", (ar + i));	
	} 
	printf("\n");
	printf("Original Matrix\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < m; j++)
		{	
			printf("%d ", *(ar + i*m + j));	
		}
		printf("\n"); 
	}
	printf("\n"); 
	printf("Reflected Matrix\n");
	for(i = 0; i < m; i++)
	{
		for(j = m-1, k = 0; j >= 0 || k < m ; j--, k++)
		{	
			printf("%d ", *(ar + i*m + j));
			*(rev + i*m + k) = *(ar + i*m + j);
		}
		printf("\n"); 
	}
	printf("\n");
	
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < m; j++)
		{	
			printf("%d ", *(rev + i*m + j));	
		}
		printf("\n"); 
	}
}
