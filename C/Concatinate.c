#include <stdio.h>
#include <string.h>

void concat(char str1[], char str2[], char str3[], int len1, int len2, int len3)
{
 	int i;

	for(i = 0; i <= len1; i++)
	{
		str3[i] = str1[i];
	}

	for(i = 0; i <= len2; i++)
	{
		str3[i + len1] = str2[i];
	}

	puts(str3);
}

main()
{
	char str1[100], str2[100];
	int i = 0, len1 = 0, len2 = 0, len3 = 0;

	printf("Enter String 1\n");
	gets(str1);
	printf("Enter String 2\n");
	gets(str2);
	system("cls");

	while(str1[i] != '\0')
	{
		len1++;
		i++;
	}

	i = 0;

	while(str2[i] != '\0')
	{
		len2++;
		i++;
	}

	len3 = len1 + len2;
	char str3[len3];
	concat(str1, str2, str3, len1, len2, len3);
}
