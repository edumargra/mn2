#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846



void runge_kutta(double a, double b, int n, double c);
double f(double x, double y);

int main() {
    runge_kutta(PI/6.,PI/3.,10,1./sqrt(3));

}

void runge_kutta(double a, double b, int n, double c) {
    double y = c;
    double h = (b-a)/n;
    double x = a;

    double k1, k2, k3, k4;

    for (int i = 1; i <= n; i++) {
        k1 = h * f(x,y);
        k2 = h * f(x + 1/2. * h, y + 1/2. * k1);
        k3 = h * f(x + 1/2. * h, y + 1/2. * k2);
        k4 = h * f(x + h, y +  k3);
        //Apliquem runge_kutta
        y = y + 1/6. * ( k1 + 2*k2 + 2*k3 + k4);

        printf("%e\n", y);
        //Preparem seguent iteracio
        x += h;
    }

}

double f(double x, double y){
    return pow(y,2.)/pow(sin(x),2.);
}