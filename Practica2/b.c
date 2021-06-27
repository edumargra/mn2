#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846


void euler_method_with_richardson(double a, double b, int n, double c, double q);
double euler_method(double x, double h, double y);
double f(double x, double y);

int main() {
    euler_method_with_richardson(PI/6.,PI/3.,10,1./sqrt(3),2);
}



void euler_method_with_richardson(double a, double b, int n, double c, double q) {
    double y = c;
    double y1 = c;
    double h = ((b-a)/n);
    double x = a;

    double h1 = ((b-a)/n)/q;
    double A00,A11,A10;

    for (int i = 1; i <= n; i++) {
        // Calculem A00: Calculem l'aproximacio de x+h amb h per euler.
        A00 = euler_method(x, h, y);
        // Calculem A10: Parallelament calculem l'aproximacio de x+h amb h1 per euler (haurem de fer dos calculs ja que h1 = h/2)
        A10 = euler_method(x, h1, y1);
        A10 = euler_method(x+h1,h1, A10);

        // Apliquem la formula de "l'algorisme de richardson" per a calcular A11.
        A11 = A10 + (A10 - A00);//

        printf("%e\n", A11);

        //Preparem per la seguent iteracio
        y = A00;
        y1 = A10;
        x += h;

    }
}

double f(double x, double y){
    return pow(y,2.)/pow(sin(x),2.);
}

double euler_method(double x, double h, double y) {
    return y + h * f(x,y);
}

double richardson(double A, double B, double q, int k){
    return A + (A-B)/(pow(q,k) - 1);
}


