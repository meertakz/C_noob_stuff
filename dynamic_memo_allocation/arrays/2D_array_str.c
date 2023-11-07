#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int main() {
    int r, i;
    char **mat;

    // row
    printf("Number of rows: ");
    scanf("%d", &r);

    mat = (char **)malloc(r * sizeof(char*));
    if (mat == NULL) {
        fprintf(stderr, "Memory allocation error #1\n");
        exit(1);
    }
    // strings
    for (i = 0; i < r; i++) {
        printf("Enter [%d]th string: ", i);
        char str[N];
        scanf(" %s", str); // Use a space before %s to avoid issues with leading whitespace

        mat[i] = (char *)malloc((strlen(str) + 1) * sizeof(char));
        if (mat[i] == NULL) {
            fprintf(stderr, "Memory allocation error #2\n");
            exit(1);
        }
        // manipulate matrix
        strcpy(mat[i], str); // Copy the input string to the allocated memory
    }

    // print matrix
    for (i = 0; i < r; i++) {
        printf("mat[%d]: %s\n", i, mat[i]);
    }
    

    // free memory
    for (i = 0; i < r; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
