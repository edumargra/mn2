/*
* Programa corresponent a l'apartat a de la Practica 1 de MN2 a la UB.
* Implementacio en C de l'algoritme iteretiu de Jacobi.
* Autors: Eduard Martin i Albert Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a, b; /* corresponding to interval [a,b] */
    int n;  /* number of interior points inside [a,b] to work on */
    double alpha, beta; /* frontier conditions */
    double epsilon; /* error tolerance */
    int max_iter;   /* max iterations */ 
    double *x, *y;  /* solution vectors corresponding to the k and k-1 iterations */
    double *delta; /* error vector corresponding to the solution difference between the k-1 and k-2 iterations */

    int num_iteracions; /* present iteration number */
    double error_estimat;   /* present approximation error of the solutions */

    x = (double *)calloc(n+2,sizeof(double));
    if(x==NULL){printf("Couldn't allocate memory");exit(1);}
    y = (double *)calloc(n+2,sizeof(double));
    if(y==NULL){printf("Couldn't allocate memory");exit(1);}
    delta = (double *)calloc(n+2,sizeof(double));
    if(delta==NULL){printf("Couldn't allocate memory");exit(1);}

    error_estimat = 1; /* initialize error to an arbitrary bigger value than epsilon */

    while (error_estimat > epsilon && num_iteracions < max_iter) {
        
        
        
        num_iteracions++;
        error_estimat = abs_error(delta,new_delta);
    }

}

/* Calculates a non-rigourus boundary for the error between two solutions*/
double abs_error(double *delta, double* new_delta) {

}

void* vector_substraction(double *delta, double *x, double *y, int n) {
    for(int i = 0; i < n; ++i) {
        delta[i] = x[i] - y[i];
    }
} 

double r(double x) {
    return x;
}

double q(double x) {
    return math.exp(x)
}

double r(double x) {
    return x * math.sin(x)(2 + math.exp(x)) + math.cos(x)(x^2 - 2)
}