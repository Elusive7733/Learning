#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[100];
	char temp[100];
	int score, i = 1;
	FILE *fptr;
	int flag;

	fptr = fopen("C:\\Users\\abdul\\Desktop\\My Codes Atom\\file.txt", "r+");
	fseek(fptr, 0, SEEK_END);
	printf("Enter firstname\n");
	gets(str);
	fprintf(fptr,"%s", &str);
	printf("Enter %s's score\n", str);
	scanf("%d", &score);
	fprintf(fptr, "\n");
	fprintf(fptr, "%d\n", score);
	printf("If you want to check score press 1\n");
	scanf(" %d", &flag);
	if(flag == 1)
	{
		fseek(fptr, 0, SEEK_SET);
		printf("Enter name\n");
		fflush(stdin);
		gets(str);
		while(!feof(fptr)){
			if(i%2 != 0){
					fflush(stdin);
					fscanf(fptr, "%s", &temp);
					if(strcmp(temp, str) == 0)
					{
						fscanf(fptr, "%d", &score);
						printf("Name = %s\n",temp);
						printf("score = %d\n", score);
					}
				}
			i++;
		}
	}
	printf("itni dafa chala loop = %d", i);
	fclose(fptr);
   return 0;
}
