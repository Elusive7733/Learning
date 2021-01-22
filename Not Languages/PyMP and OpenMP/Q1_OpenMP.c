#include <math.h>
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

long double x, fact[150], pwr[150];


void power(){
    int i;
    for(i = 0; i < 150; i++){
        pwr[i] = pow(x, i);
    }
}

void factorial(){
    long double num;
    int i, j;
    fact[0] = 1.0;
    for(i = 1; i < 150; i++){
        num = 1.0;
        for(j = i; j > 0; j--){
            num = num * j;
        }
        fact[i] = num;
    }
}

long double expo(){
    int i;
    long double s = 0;
    for(i = 0; i < 150; i++){
        s = s + (pwr[i]/fact[i]);
    }
    return s;
}


int main(){
    int i;
    long double sum = 0;
    printf("Exponential: Enter value of x (between 0 and 100): ");
    scanf("%Lf", &x);
    printf(".....Creating Threads.....\n");
    #pragma omp parallel
	{
		omp_set_num_threads(2);
        int total_threads = omp_get_num_threads();
        #pragma omp for
		for(i = 0; i < total_threads; i++){
			if(i == 0){
                power();
            }
            if(i == 1){
                factorial();
            }
		}
    }
    printf(".....Threads Created.....\n");
    printf(".....Result Collected.....\n\n");
    #pragma omp parallel master
    {
        sum = expo();
    }
    printf("Exponential: Value of %.2Lf is: %Lf\n\n", x, sum);
	return 0;
}

