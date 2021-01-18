#include <math.h>
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>

long double x, fact[150], pwr[150], s[1];


void power(void *temp){
    int i;
    for(i = 0; i < 150; i++){
        pwr[i] = pow(x, i);
    }
}

void factorial(void *temp){
    long double num;
    int i, j;
    
}

void *exp(void *temp){

}


int main(){

	return 0;
}

