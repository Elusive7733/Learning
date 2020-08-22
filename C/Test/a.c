#include <stdio.h>

main()
{
	int i, len, highest = -99;
	printf("Enter No of scores \n");
	scanf("%d", &len);
	int scr[len];
	for(i = 0; i < len; i++)
	{
		scanf("%d", &scr[i]);
		if(scr[i] > highest)
		{
			highest = scr[i];
		}
	}
	
	printf("%d" ,highest);	
}
