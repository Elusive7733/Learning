#include <stdio.h>
#include <math.h>

void main()
{
	int T, a, b, c, i;
	scanf("%d", &T);
	char ar[T];

	for(i = 0; i < T; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		a -= c;
		b -= c;
		a = abs(a);
		b = abs(b);
		if(a == b)
		{
			ar[i] = 'C';
		}
		else if(a > b)
		{
			ar[i] = 'B';
		}
		else
		{
			ar[i] = 'A';
		}
	}

	for(i = 0; i < T; i++)
	{
		if(ar[i] == 'C')
		{
			printf("Mouse C\n");
		}
		else
		{
			printf("Cat %c\n", ar[i]);
		}
	}
}
