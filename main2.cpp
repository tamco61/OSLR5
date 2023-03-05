#include "lib1.h"
#include "lib2.h"
#include <stdio.h>
#include <dlfcn.h>

void help(){
    printf("USAGE: K arg1 arg2 ... arg N\n");
    printf("K = 0 - if you want to change the implementation\n");
    printf("K = 1 - if you want to take the derivative. arg1 = point A, arg2 = increment\n");
    printf("K = 2 - if you want to calculate the number pi. arg1 = accuracy\n");
}

int main(){
    help();
    int command, curLib = 0;
    char* libs[] = {"./libd1.so", "./libd2.so"};
    void* lib_handler = dlopen(libs[curLib], RTLD_LAZY); // initial library is first (with implementation1)
    if (lib_handler == NULL){
        printf("sorry");
        return 1;
    }
    float (*SinIntegral)(float A, float B, float e);
    int (*PrimeCount)(int A, int B);
    SinIntegral = (float (*)(float, float, float))dlsym(lib_handler, "SinIntegral");
    PrimeCount = (int (*)(int, int))dlsym(lib_handler, "PrimeCount");
    while(scanf("%d", &command) != EOF){
        if (command == 0){
            dlclose(lib_handler);
            curLib = 1 - curLib;
            lib_handler = dlopen(libs[curLib], RTLD_LAZY);
            if (lib_handler == NULL){
                return 1;
            }
            SinIntegral = (float (*)(float, float, float))dlsym(lib_handler, "SinIntegral");
            PrimeCount = (int (*)(int, int))dlsym(lib_handler, "PrimeCount");
        }
        else if (command == 1){
            float A, B, e;
            scanf("%f %f %f", &A, &B, &e);
            printf("SinIntegral'(%f, %f) = %f\n", A, B, SinIntegral(A, B, e));
        }
        else if (command == 2) {
            int A, B;
            scanf("%d %d", &A, &B);
            printf("PrimeCount = %f\n", PrimeCount(A, B));

        } else{
            help();
            return -1;
        }
    }

    return 0;
}