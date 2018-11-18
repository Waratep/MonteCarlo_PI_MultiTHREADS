#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_THREADS 64
#define SEED 35791246


static long steps = 1000000000;
double step;

int main (int argc, const char *argv[]) {

    long int i,j,count;
    double start, delta;
    double x,y,z,pi;

    step = 1.0/(double) steps;

    // Compute parallel compute times for 1-MAX_THREADS
    // for (j=1; j<= MAX_THREADS; j++) {

        // printf(" running on %d threads: ", j);

        // This is the beginning of a single PI computation 
        // omp_set_num_threads(j);

        // double start = omp_get_wtime();


        // #pragma omp parallel for reduction(+:sum) private(x)
        // #pragma omp parallel default(none) \ private(i,x,y,z) shared(count,steps) 
        // #pragma omp for
        for (i=0; i < steps; i++) {
            srand(SEED);
            x = (double)rand()/RAND_MAX;
            y = (double)rand()/RAND_MAX;
            z = x*x+y*y;
            if (z<=1) count++;
            pi = (double)count/steps*4;
            printf("step %ld : %.30g\n",i,pi);

        }


        // printf("PI = %.30g computed in %.4g seconds\n", pi, delta);

    // }
    

}