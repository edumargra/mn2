#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846


void runge_kutta_with_richardson(double a, double b, int n, double c, double q);
double runge_kutta(double x, double h, double y);
double f(double x, double y);

int main() {
    runge_kutta_with_richardson(PI/6.,PI/3.,10,1./sqrt(3),2);

}



void runge_kutta_with_richardson(double a, double b, int n, double c, double q) {
    double y = c;
    double y1 = c;
    double h = ((b-a)/n);
    double x = a;

    double h1 = h/q;

    double A00,A10,A11;

    for (int i = 1; i <= n; i++) {
        // Calculem A00: Necessitem h i el punt inicial i fem euler.
        // Calculem A10: A partir de l'x d'A00 i h1 calculem el punt anterior i fem euler.
        // Apliquem la formula de "l'algorisme de richardson" per a calcular A11.
        A00 = runge_kutta(x, h, y);
        A10 = runge_kutta(x, h1, y1);
        A10 = runge_kutta(x+h1, h1, A10);

        A11 = A10 + (A10 - A00)/(pow(q,1 + 3)-1.);

       
        y = A00;
        y1 = A10;
        printf("%e\n", A11);
        x += h;
    }

}

double f(double x, double y){
    return pow(y,2.)/pow(sin(x),2.);
}

double runge_kutta(double x, double h, double y) {

    double k1, k2, k3, k4;

    k1 = h * f(x,y);
    k2 = h * f(x + 1/2. * h, y + 1/2. * k1);
    k3 = h * f(x + 1/2. * h, y + 1/2. * k2);
    k4 = h * f(x + h, y +  k3);
    return y + 1/6. * ( k1 + 2*k2 + 2*k3 + k4);

}
