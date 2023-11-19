#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototypes
char **read_file(int *dim);
void play_r(char **scheme, char *column, int n, int row, FILE *fp);


int main()
{
    char *column, **scheme;
    char filename[20];
    FILE *fp;
    int n, i;

    scheme = read_file(&n);
    column = (char *) malloc ((n+1) * sizeof(char));

    if (column == NULL){
        fprintf(stderr, "memory allocation error (1)\n");
        exit(1);
    }
    column[n] = '\0';

    fprintf(stdout, "output file name?  ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    play_r(scheme, column, n, 0, fp);
    fclose(fp);

    for (i=0; i<n; i++){
         free(scheme[i]);
    }
    free(scheme);
    free(column);
    return 0;
}


// load input scheme from the file
char **read_file(int *dim){
    char filename[20], line[10], **scheme;
    int i, n=0;
    FILE *fp;

    fprintf(stdout, "input file name?   ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL){
        fprintf(stderr, "input file open error\n");
        exit(1);
    }
    // count number of rows
    while (fscanf(fp, "%s", line)!=EOF){
        n++;
    }
    fclose(fp);


    // read and store
    scheme = (char **) malloc (n * sizeof(char *));
    if (scheme == NULL){
        fprintf(stderr, "memory allocation error (2)\n");
        exit(1);
    }
    fp = fopen(filename, "r");
    for (i=0; i<n; i++){
        fscanf(fp, "%s", line);
        scheme[i] = strdup(line);
    }
    fclose(fp);
    *dim = n;
    return scheme;
}


// column expansion recursive function
void play_r(char **scheme, char *column, int n, int row, FILE *fp) {
    int i;

    if (row >= n) {
        fprintf(fp, "%s\n", column);
        return;  // Added a return statement to stop further execution in this branch
    }
    for (i = 0; i < strlen(scheme[row]); i++) {
        column[row] = scheme[row][i];
        play_r(scheme, column, n, row + 1, fp);
    }
    column[row] = '\0';  // Reset the column[row] after the recursive calls
}
