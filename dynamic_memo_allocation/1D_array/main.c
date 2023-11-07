#include <stdio.h>
#include <stdlib.h>

#define FILEPATH "input1.txt"
#define N 1

int main() {
    int *v1, *v2;
    int size = N;
    int tmp, i = 0;

    v1 = (int *)malloc(size * sizeof(int));
    if (v1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    FILE *fp;
    fp = fopen(FILEPATH, "r");
    if (fp == NULL) {
        printf("Failed to open the file\n");
        free(v1);
        return 1;
    }

    while (fscanf(fp, "%d", &tmp) != EOF) {
        if (i >= size) {
            size = size * 2;
            v2 = (int *)realloc(v1, size * sizeof(int));

            if (v2 == NULL) {
                printf("Memory reallocation failed\n");
                free(v1);
                fclose(fp);
                return 1;
            }
            v1 = v2;
        }
        v1[i] = tmp;
        i++;
    }

    fclose(fp);

    // Print the integers
    for (int j = 0; j < i; j++) {
        printf("%d ", v1[j]);
    }
    printf("\n");

    // free the dynamically allocated memory
    free(v1);

    return 0;
}
