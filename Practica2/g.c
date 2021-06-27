#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846



void adams_bashforth_3(double a, double b, int n, double c);
void adams_bashforth_4(double a, double b, int n, double c);
void adams_bashforth_5(double a, double b, int n, double c);
double f(double x, double y);

int main() {
    printf("Adams Bashfort 3\n");
    adams_bashforth_3(PI/6.,PI/3.,10,1./sqrt(3));
    printf("-------\n");
    printf("Adams Bashfort 4\n");
    adams_bashforth_4(PI/6.,PI/3.,10,1./sqrt(3));
    printf("-------\n");
    printf("Adams Bashfort 5\n");
    adams_bashforth_5(PI/6.,PI/3.,10,1./sqrt(3));

}



void adams_bashforth_3(double a, double b, int n, double c) {
    double y1 = c;
    double h = (b-a)/n;
    double x = a;

    double y2 = y1 + h * f(x,y1);
    printf("Euler: %e\t", y2);
    x += h;
    printf("Tan: %e\n", tan(x));

    double y3 = y2 + h * f(x,y2);
    printf("Euler: %e\t", y3);
    x += h;
    printf("Tan: %e\n", tan(x));

    double y4;
    for (int i = 3; i <= n; i++) {
        y4 = y3 + h * (23/12.*f(x,y3) - 4/3.*f(x-h,y2) + 5/12. * f(x-2*h, y1));
        printf("Euler: %e\t", y4);
        x += h;
        printf("Tan: %e\n", tan(x));
        y1 = y2;
        y2 = y3;
        y3 = y4;
    }

}

void adams_bashforth_4(double a, double b, int n, double c) {
    double y1 = c;
    double h = (b-a)/n;
    double x = a;

    double y2 = y1 + h * f(x,y1);
    printf("Euler: %e\t", y2);
    x += h;
    printf("Tan: %e\n", tan(x));

    double y3 = y2 + h * f(x,y2);
    printf("Euler: %e\t", y3);
    x += h;
    printf("Tan: %e\n", tan(x));

    double y4= y3 + h * f(x,y3);
    printf("Euler: %e\t", y4);
    x += h;
    printf("Tan: %e\n", tan(x));

    double y5;
    for (int i = 4; i <= n; i++) {
        y5 = y4 + h * (55/24.*f(x,y4) - 59/24.*f(x-h,y3) + 37/24.* f(x-2*h, y2) - 3/8.*f(x-3*h,y1));
        printf("Euler: %e\t", y5);
        x += h;
        printf("Tan: %e\n", tan(x));
        y1 = y2;
        y2 = y3;
        y3 = y4;
        y4 = y5;
    }

}

void adams_bashforth_5(double a, double b, int n, double c) {
    double y1 = c;
    double h = (b-a)/n;
    double x = a;

    double y2 = y1 + h * f(x,y1);
    printf("Euler: %e\t", y2);
    x += h;
    printf("Tan: %e\n", tan(x));

    double y3 = y2 + h * f(x,y2);
    printf("Euler: %e\t", y3);
    x += h;
    printf("Tan: %e\n", tan(x));

    double y4= y3 + h * f(x,y3);
    printf("Euler: %e\t", y4);
    x += h;
    printf("Tan: %e\n", tan(x));

    double y5 = y4 + h * f(x,y4);
    printf("Euler: %e\t", y5);
    x += h;
    printf("Tan: %e\n", tan(x));

    double y6;
    for (int i = 5; i <= n; i++) {
        y6 = y5 + h * (1901/720.*f(x,y5) - 1387/360.*f(x-h,y4) + 109/30. * f(x-2*h, y3) + 637/360. * f(x-3*h, y2) + 251/720. * f(x-4*h, y1));
        printf("Euler: %e\t", y6);
        x += h;
        printf("Tan: %e\n", tan(x));
        y1 = y2;
        y2 = y3;
        y3 = y4;
        y4 = y5;
        y5 = y6;
    }

}

double f(double x, double y){
    return pow(y,2.)/pow(sin(x),2.);
}