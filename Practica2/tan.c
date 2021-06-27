#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846


int main() {
    //euler_method(PI/6.,PI/3.,10,1./sqrt(3));
    double x = PI/6.;
    double n = 10;
    double h = (PI/3.- PI/6.)/n;

    for(int i =0; i < 10; i++){
        x += h;
        printf("%e\n", tan(x));
    }

}