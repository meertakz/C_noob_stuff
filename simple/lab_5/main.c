#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DEBUG 1

void gray (int **, int, int, int);
int **malloc2d (int, int);
void printMat (int **, int, int);


int main (int argc, char *argv[])
{
    int n, N;
    int **mat;

    n = atoi (argv[1]);
    N = pow (2, n);
    mat = malloc2d (N, n);

    gray (mat, n, N, 0);

    printf ("Gray Code on %d bits:\n", n);
    printMat (mat, n, N);

    return 0;
}


void gray (int **mat,int n, int N, int l)
{
    int mirror, r, c;

    // Termination Condition
    if (l>=n) {
        return;
    }

    // Reflection Column
    mirror = pow (2,l);

    // Reflection
    for (c=0; c<l; c++) {
        for (r=0; r<mirror; r++) {
            mat[2*mirror-r-1][n-c-1] = mat[r][n-c-1];
        }
    }

    // Put all 0s Above and all 1s Below the Mirror
    for (r=0; r<mirror; r++) {
        mat[r][n-l-1] = 0;
        mat[mirror+r][n-l-1] = 1;
    }

    
#if DEBUG
    // Debug Printing
    printf ("Matrix at Recursion Level %d:\n", l);
    printMat (mat, n, N);
#endif
    // Recur
    gray (mat, n, N, l+1);
}


int **malloc2d (int N, int n)
{
    int r;
    int **mat;

    mat = (int **) malloc (N * sizeof (int *));
    if (mat==NULL) {
        fprintf (stdout, "allocation Error.\n");
        exit (1);
    }
    for (r=0; r<N; r++) {
        mat[r] = (int *) malloc (n * sizeof (int));
        if (mat[r]==NULL) {
            fprintf (stdout, "Allocation Error.\n");
            exit (1);
        }
    }

    return (mat);
}


void printMat (int **mat,int n,int N)
{
    int r, c;

    for (r=0; r<N; r++) {
        for (c=0; c<n; c++) {
            fprintf (stdout, "%d ", mat[r][c]);
        }
        fprintf (stdout, "\n");
    }
}
