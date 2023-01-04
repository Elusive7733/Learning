#include <stdio.h>

/*void pointref(int ar[][], int row)
{
	int i, j, temp;
	
	for(i = 0; i <= row-1; i++)
	{
		for(j = 0; j <= 1; j++)
		{
			temp = ar[i][j+1];
			ar[i][j+1] = ar[i][j];
			ar[i][j] = temp;
		}			
	}
}*/

main()
{
	int row, i, j, temp;
	printf("Enter row\n");
	scanf("%d", &row);
	
	int ar[row-1][1];
	
	for(i = 0; i <= row-1; i++)
	{
		for(j = 0; j <= 1; j++)
		{
			printf("Enter ar[%d][%d]\n", i, j);
			scanf("%d", &ar[i][j]);
		}			
	}

	//pointref(ar);
	
	for(i = 0; i <= row-1; i++)
	{
		for(j = 0; j <= 1; j++)
		{
			temp = ar[i][j+1];
			ar[i][j+1] = ar[i][j];
			ar[i][j] = temp;
		}			
	}
	
	for(i = 0; i <= row-1; i++)
	{
		for(j = 0; j <= 1; j++)
		{
			printf("%d", ar[i][j]);
		}
	}	
}

