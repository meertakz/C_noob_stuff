#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *v;

    fprintf(stdout, "introduce n    #");
    scanf("%d", &n);

    // allocation for array that will hold n values //
    v = (int *) malloc(n * sizeof(int));
    // check //
    if (v == NULL){
        fprintf(stderr, "memory allocation error");
        exit(1);}

    int i, *p;

    for (i=0, p=v; i<n; i++, p++){
        fprintf(stdout, "v[%d] ==> ", i);
        scanf("%d", p);
    }

    for (i=0, p=v; i<n; i++, p++){
        fprintf(stdout, "v[%d] ==> %d\n", i, *p);
    }
    free(v);
}
