#include <stdlib.h>
#include <stdio.h>

int main()
{
    int r, c, i, j;
    int **mat;

    // row
    printf("number of rows  #");
    scanf("%d",&r);

    mat = (int**)malloc(r*sizeof(int*));
    if (mat == NULL){
        fprintf(stderr, "memory allocation error\n");
        exit(1);
    }

    // col
    printf("number of cols  #");
    scanf("%d",&c);

    for (i=0; i<r; i++)
    {
        mat[i] = (int*)malloc(c*sizeof(int));
        if (mat[i]==NULL)
        {
            fprintf(stderr, "memory allocation error\n");
            exit(1);
        }
    }

    // matrix manipulation
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("mat[%d][%d]:", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // print matrix
    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // free memory
    for(i=0;i<r;i++){
        free(mat[i]);
    }
    free(mat);
}
