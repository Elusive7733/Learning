#include <stdio.h>
#include <string.h>

void main()
{
char romn[1000]; 					
int nudisp = 0, value[1000], loopc, i; 
printf("Roman Numerals : (I, V, X, L, C, D, M)\n");
printf("Enter the Roman Numerals : \n");
scanf("%s", &romn); 				
loopc = strlen(romn) - 1; 		
for (i = 0; i <= loopc; i++ ) 
{
	switch(romn[i])
	{ 
	   case 'I': value[i] = 1; break; 
        case 'V': value[i] = 5; break;
        case 'X': value[i] = 10; break;
        case 'L': value[i] = 50; break;   
        case 'C': value[i] = 100; break;
        case 'D': value[i] = 500; break;
        case 'M': value[i] = 1000; break;
    	default : value[i] = -1 ; 
	} 
} 
i = 0 ; 
nudisp = nudisp + value[loopc]; 

	while ( i < loopc)
	{
		if (value[i] < value[i + 1]) 
		{
			nudisp = nudisp - value[i];
		}
		else  
		{
			nudisp = nudisp + value[i];
		}
	i = i + 1; 
	}
	if (nudisp == -1)
	{
		printf("Incorrect data entered");
	}
	else
	{
		printf("\n");
		printf("Answer in Decimal :\n%d ", nudisp);
	}
}
	
