#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846



void euler_method(double a, double b, int n, double c);
double f(double x, double y);

int main() {
    euler_method(PI/6.,PI/3.,10,1./sqrt(3));

}



void euler_method(double a, double b, int n, double c) {
    double y = c;
    double h = (b-a)/n;
    double x = a;
    for (int i = 1; i <= n; i++) {
        //Apliquem euler per calcular l'aproximacio de x+h
        y = y + h * f(x,y);

        printf("%e\n", y);

        //Preparem per la seguent iteracio
        x += h;
    }

}

double f(double x, double y){
    return pow(y,2.)/pow(sin(x),2.);
}
