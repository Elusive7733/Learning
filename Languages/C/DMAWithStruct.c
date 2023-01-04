#include <stdio.h>
#include <stdlib.h>

typedef struct b{
	int accnum;
	char name[50];
	int balance;
}bank;

int details(bank *x,int n)
{
	int i, temp, flag = 0;
	while(flag != 1)
	{
		printf("Enter Account Number to check balance\n");
		scanf("%d", &temp);

		for(i = 0; i < n; i++)
		{
			if(temp == (x+i)->accnum)
			{
				printf("Account Number = %d\nName = ", (x+i)->accnum);
				puts((x+i)->name);
				printf("Balance = %d\n", (x+i)->balance);
			}
		}
		printf("Enter 0 to check the balance of another user else Enter 1\n");
		scanf("%d", &flag);
	}
	return 0;
}
 int main()
{
	bank *p;
	int n, i, temp, flag = 0;
	printf("Enter Number of users :\n");
	scanf("%d", &n);
	p = (bank*) malloc(n*sizeof(bank));

	for(i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("Enter Name\n");
		fflush(stdin);
		gets((p+i)->name);
		printf("Enter Account number\n");
		scanf("%d", &(p+i)->accnum);
		printf("Enter Balance\n");
		fflush(stdin);
		scanf("%d", &(p+i)->balance);
		printf("\n");
	}
	system("cls");
	details(p, n);
	return 0;
}
