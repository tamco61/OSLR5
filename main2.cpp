#include <stdio.h>
#include <dlfcn.h>
#include "lib1.h"
#include "lib2.h"
#include <assert.h>

void help(){
    printf("USAGE: K arg1 arg2 ... arg N\n");
    printf("K = 0 - if you want to change the implementation\n");
    printf("K = 1 - if you want to take the SinIntegral. arg1 = point A, arg2 = B, arg3 = e\n");
    printf("K = 2 - if you want to take the PrimeCount. arg1 = A, arg2 = B\n");
}

int main(){
    
    help();
    int command, curLib = 0;
    char* libs[] = {"./libd1.so", "./libd2.so"};
    void* lib_handler = dlopen(libs[curLib], RTLD_LAZY); // initial library is first (with implementation1)
    float (*SinIntegral)(float A, float B, float e);
    int (*PrimeCount)(int A, int B);

    SinIntegral = (float (*)(float, float, float))dlsym(lib_handler, "SinIntegral");
    PrimeCount = (int (*)(int, int))dlsym(lib_handler, "PrimeCount");

    while(scanf("%d", &command) != EOF){
        if (command == 0){
            if (dlclose(lib_handler))
                return 1;

            curLib = 1 - curLib;
            lib_handler = dlopen(libs[curLib], RTLD_LAZY);
            if (lib_handler == NULL){
                return 1;
            }
            SinIntegral = (float (*)(float, float, float))dlsym(lib_handler, "_Z11SinIntegralfff");
            PrimeCount = (int (*)(int, int))dlsym(lib_handler, "_Z10PrimeCountii");
            if (SinIntegral == NULL) return 1;
            if (PrimeCount == NULL) return 1; 
        }
        else if (command == 1){
            float A, B, e;
            scanf("%f %f %f", &A, &B, &e);
            printf("SIN\n");
            printf("SinIntegral(%f, %f) = %f\n", A, B, SinIntegral(A, B, e));
        }
        else if (command == 2) {
            int A, B;
            scanf("%d %d", &A, &B);
            printf("Pr\n");
            printf("PrimeCount = %d\n", PrimeCount(A, B));

        } else{
            help();
            return -1;
        }
    }

    return 0;
}
