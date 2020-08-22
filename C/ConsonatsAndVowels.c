#include <stdio.h>

int v = 0, c = 0;

int vc(char array[])
{
	int i;
	for (i = 0 ; i <= strlen(array)-1 ; i++)
	{
		if (array [i] == 'a' || array [i] == 'e' || array [i] == 'i' || array [i] == 'o' || array [i] == 'u' || array [i] == 'A' || array [i] == 'E' || array [i] == 'I' || array [i] == 'O' || array [i] == 'U')
		{
			v++;
		}
		else
		{
			c++;
		}
	}
}

int main()
{
	char array[100];
	printf("Enter a string\n");
	gets(array);
	vc(array);
	printf("The number of vowels are %d\n", v);
	printf("The number of consonants are %d\n", c);
}

