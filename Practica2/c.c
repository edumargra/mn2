#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846



void adams_bashforth(double a, double b, int n, double c);
double f(double x, double y);

int main() {
    adams_bashforth(PI/6.,PI/3.,10,1./sqrt(3));

}



void adams_bashforth(double a, double b, int n, double c) {
    double y1 = c;
    double h = (b-a)/n;
    double x = a;

    //Apliquem adam-bashfort (cas especial y2 inicial)
    double y2 = y1 + h * f(x,y1);
    printf("%e\n", y2);
    x += h;

    double y3;
    for (int i = 2; i <= n; i++) {
        //Apliquem adam-bashfort
        y3 = y2 + h/2. * (3*f(x,y2) - f(x-h,y1));

        printf("%e\n", y3);

        //Preparem per la seguent iteracio
        x += h;
        y1 = y2;
        y2 = y3;
    }

}

double f(double x, double y){
    return pow(y,2.)/pow(sin(x),2.);
}