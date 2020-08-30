#include <stdio.h>
#include <math.h>

int main(void){
    int a = 5;
    int b = 9;

    printf("Normal modulo : %d\n", (a % b));
    printf("Fmod: %lf\n", fmod(a, b));

    return 0;

}
