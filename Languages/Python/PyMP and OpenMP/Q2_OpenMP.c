#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int count = 0;
#define COUNT_DONE 10 
#define COUNT_HALT1 3 
#define COUNT_HALT2 6
omp_lock_t lock;

void function1(){
    for(;;){
        omp_init_lock(&lock);
        while (count >= COUNT_HALT1 && count <= COUNT_HALT2){
            sleep(1);
        }
        omp_set_lock(&lock);
        count++;
        printf("Function 1, Counter Value: %d\n", count);
        omp_unset_lock(&lock);
        if(count >= COUNT_DONE){
            return;
        }
    }
}

void function2(){
    for(;;){
        omp_init_lock(&lock);
        while (count < COUNT_HALT1 || count > COUNT_HALT2){
            sleep(1);
        }
        omp_set_lock(&lock);
        count++;
        printf("Function 2, Counter Value: %d\n", count);
        omp_unset_lock(&lock);
        if(count >= COUNT_DONE){
            return;
        }
    }
}

int main(){
    int i = 0;
    #pragma omp parallel
    {   
        omp_set_num_threads(2);
        int total_threads = omp_get_num_threads();
        #pragma omp for
        for(i = 0; i < total_threads; i++){
            if(i == 0){
                function1();
            }
            if(i == 1){
                function2();
            }
        }
    }
    return 0;
}