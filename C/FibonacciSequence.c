#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i, next = 1, prev = 0, sum = 0, N;

	printf("Enter N\n");
	scanf("%d", &N);
	system ("clear");

	for(i = 0 ; i < N; i++)
	{
		if(i == N-1){
			printf(" %d", prev);
		}
		else{
			printf(" %d, ", prev);
		}
		sum = prev + next;
		prev = next;
		next = sum;
	} 
	printf("\n");
}
