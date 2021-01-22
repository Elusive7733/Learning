#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i, x, j, larg = -250;
	printf("Enter Number of Elements\n");
	scanf("%d", &x);
	int *ar = (int *) calloc(x, sizeof(int));
	for(i = 0; i < x; i++)
	{
		scanf("%d", (ar + i));
		if(*(ar + i) >= larg)
		{
			larg = *(ar + i);
		}
	}
	printf("Largest = %d", larg);
}
