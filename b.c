/*
* Programa corresponent b l'apartat a de la Practica 1 de MN2 a la UB.
* Implementacio en C de l'algoritme iteratiu de Gauss-Seidel.
* Autors: Eduard Martin i Albert Catalan
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI atan(1)*4

double indep_term_i(double x_i, double h, int i, double alpha, double beta, int n);
double diagonal_inf_i(double x_i, double h);
double diagonal_sup_i(double x_i, double h);
double diagonal_i(double x_i, double h);

double abs_error(double delta_past, double delta);
double norm_inf(double *x, double *y, int n);

double p(double x);
double q(double x);
double r(double x);


int main() {
    double a, b; /* corresponding to interval [a,b] */
    int n;  /* number of interior points inside [a,b] to work on */
    double alpha, beta; /* frontier conditions */
    double epsilon; /* error tolerance */
    int max_iter;   /* max iterations */ 

    double *x, *y;  /* solution vectors corresponding to the k+1 and k iterations */
    double *diagonal, *diagonal_inf, *diagonal_sup, *indep_term; /* corresponding to the supra,infra and diagonal of the A matrix and the independent term */

    double delta = 0; /* inifinty norm of the error corresponding to the difference between the k+1 and k solution iterations */
    double delta_past = 0; /* inifinty norm of the error corresponding to the difference between the k and k-1 solution iterations */ 

    int num_iteracions = 0; /* present iteration number */
    double error_estimat = 1;   /* present approximation error of the solutions iteration, initialized to an arbitrary value bigger than epsilon */

    a = 0;
    b= 2*PI;
    n = 100;
    alpha = 0;
    beta = 0;
    max_iter = 3000;
    epsilon = pow(10,-10);

    
    x = (double *)calloc(n,sizeof(double));
    if(x==NULL){printf("Couldn't allocate memory");exit(1);}
    y = (double *)calloc(n,sizeof(double));
    if(y==NULL){printf("Couldn't allocate memory");exit(1);}

    diagonal = (double *)calloc(n,sizeof(double));
    if(diagonal==NULL){printf("Couldn't allocate memory");exit(1);}
    diagonal_sup = (double *)calloc(n,sizeof(double));
    if(diagonal_sup==NULL){printf("Couldn't allocate memory");exit(1);}
    diagonal_inf = (double *)calloc(n,sizeof(double));
    if(diagonal_inf==NULL){printf("Couldn't allocate memory");exit(1);}
    indep_term = (double *)calloc(n,sizeof(double));
    if(indep_term==NULL){printf("Couldn't allocate memory");exit(1);}
    

    /* Ax=r
    * A is a tridiagonal matrix, which makes Cholesky decomposition unnecessary.
    * c are the elements of the upper diagonal, b of the main diagonal and a of the lower diagonal.
    * The ith equation of the system will be Xi = (Ri-Ai*Xi-1-Ci*Xi+1)/Bi (caps where used for easier differentiation between elements and indices)
    * Therefore, (parenthesees used as iteration number) 
    * Jacobi: Xi(k+1)=(Ri-Ai*X_{i-1}(k)-Ci*Xi+1(k))/Bi
    * Gauss-Seidel: Xi(k+1)=(Ri-Ai*X_{i-1}(k+1)-Ci*X_{i+1}(k))/Bi
    */
    double h;
    double pt;
    h = (b-a)/(n+1);
    /* REMEMBER: the first and last value of the solution is already known
    * we will only compute the soltuions vlaue for the interior points
    * therefore, to simplify, the ith position of the vector X represents the (i+1)th solution
    */
    /*if necessary, we could compute the values inside the solution loop for memory saving*/
    for(int i=0; i < n; ++i) {
        pt = a+h*(i+1);
        diagonal[i] = diagonal_i(pt, h);
        diagonal_sup[i] = diagonal_sup_i(pt, h);
        diagonal_inf[i] = diagonal_inf_i(pt, h);
        indep_term[i] = indep_term_i(pt, h, i+1, alpha, beta, n);
        //printf("Iterations values %e %e %e %e\n", diagonal[i], diagonal_sup[i], diagonal_inf[i], indep_term[i]);
    }

    while (error_estimat > epsilon && num_iteracions < max_iter) {
        
        /* Special case: the first matrix row only has the diagonal and supra-diagonal element non-zero */
        x[0] = (indep_term[0] - diagonal_sup[0] * y[1])/diagonal[0];
        /* General case*/
        for(int i = 1; i < n-1; ++i) {
            x[i] = (indep_term[i] - diagonal_inf[i] * x[i-1] - diagonal_sup[i] * y[i+1])/diagonal[i];
        }
        /* Special case: the last matrix row only has the diagonal and the infra-diagonal element non-zero*/
        x[n-1] = (indep_term[n-1] - diagonal_inf[n-1] * x[n-2])/diagonal[n-1];
        
        delta = norm_inf(x, y, n);
        
        if( num_iteracions > 0){
            error_estimat = abs_error(delta_past, delta); //sempre es positiu, sino molt mala aproximacio estas fent
        }
        
        /* Print for control 
        if( num_iteracions < 10 ){
            printf("Interacio %d, amb error %e, delta %e i primer, segon i ultim element %e %e %e\n", num_iteracions, error_estimat, delta, x[0], x[1], x[n-1]);
        }
        */

        /* Prepare for next iteration*/
        for(int i=0; i<n ; ++i){
                y[i]=x[i];
        }
        num_iteracions++;
        delta_past = delta;
    }

    /* Final print-out following estipulated format*/
    printf("%e, %e, %d, %e, %e, %d, %e, %d, %e\n",a , b, n, alpha, beta, max_iter, epsilon, num_iteracions, error_estimat);
    for(int i = 0; i < n ; ++i){
        printf("%e\n", y[i]);        
    }

    /* free reserved memory*/
    free(x); free(y); free(diagonal_inf); free(diagonal); free(diagonal_sup); free(indep_term);

}
double indep_term_i(double x_i, double h, int i, double alpha, double beta, int n) {
    if (i == 1){
        return pow(h,2)/2*(r(x_i) - 2*diagonal_inf_i(x_i, h)*alpha/pow(h,2)); 
    }
    if (i == n){
        return pow(h,2)/2*(r(x_i) - 2*diagonal_sup_i(x_i, h)*beta/pow(h,2)); 
    }
    return r(x_i)*pow(h,2)/2;
}

double diagonal_inf_i(double x_i, double h) {
    return -1./2*(1 + p(x_i)*h/2.);
}

double diagonal_sup_i(double x_i, double h) {
     return -1./2*(1 - p(x_i)*h/2.);
}

double diagonal_i(double x_i, double h) {
     return (1. + q(x_i)*pow(h,2)/2.);
}

/* Calculates a non-rigourus boundary for the error between two solutions iterations*/
double abs_error(double delta_past, double delta) {
    return pow(delta,2)/(delta_past-delta);
}

double norm_inf(double *x, double *y, int n) {
    double norm,d;
	norm=0;

    for(int i=0; i<n; ++i){
        d=x[i]-y[i]; 
        if(fabs(d)>norm){  
            norm=fabs(d);
        }
    }
	return norm; 
}

double p(double x) {
    return x;
}

double q(double x) {
    return exp(x);
}

double r(double x) {
    return x * sin(x)*(2 + exp(x)) + cos(x)*(pow(x,2) - 2);
}