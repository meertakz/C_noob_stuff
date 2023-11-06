#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK_VERSION 0
#define max(R,C) ((R>C)?R:C)

/// ** function declarations ** ///
char **malloc2d(int, int);
char **free2d(char**, int);
void find(char*, char**, char**, int, int);
int find_all(int, int, char*, char**, char**, int, int);


/// ** main ** ///
int main(int argc, char *argv[]){
    // declarations
    char **matrixIn, **matrixOut;
    char *word;
    int i, j, R, C;
    FILE *fp;
    // parameter check
    if (argc < 4){
        fprintf(stderr, "error: missing parameter!\n");
        fprintf(stderr, "run as: %s <matrixFile> <wordFile> <outputFile>\n", argv[0]);
        return 1;
    }


    // first file read
    fp = fopen(argv[1], "r");
    if (fp == NULL){
        fprintf(stderr, "file open error ==> <%s>\n", argv[1]);
        return 1;
    }
    // file components check
    if (fscanf(fp, "%d%d%*c", &R, &C)==EOF){
        fprintf(stderr, "file read error\n");
        return 1;
    }


    // memory allocation
    matrixIn = malloc2d(R,C);
    matrixOut = malloc2d(R,C);
    word = (char*) malloc ((max(R,C)+1)*sizeof(char));
    // memory allocation check
    if(word==NULL){
        fprintf(stderr, "memory allocation error.\n");
        return 1;
    }
    // read and populate
    for (i=0; i<R; i++){
        for (j=0; j<C; j++){
            fscanf(fp, "%c", &matrixIn[i][j]);
        }
        fscanf(fp, "%*c");
    }
    fclose(fp);


    // second file read
    fp = fopen(argv[2], "r");
    if (fp == NULL){
        fprintf(stderr, "file open error ==> <%s>\n", argv[2]);
        return 1;
    }
    // finding words in puzzle
    while (fscanf (fp, "%s", word) != EOF){
        find(word, matrixIn, matrixOut, R, C);
    }
    fclose(fp);


    // writing to a file
    fp = fopen(argv[3], "w");
    if (fp == NULL){
        fprintf(stderr, "file open error ==> <%s>\n", argv[3]);
        return 1;
    }
    for (i=0; i<R; i++){
        for (j=0; j<C; j++){
            fprintf(fp, "%c", matrixOut[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    // free memory
    free (word);
    matrixIn = free2d(matrixIn, R);
    matrixOut = free2d(matrixOut, R);
    return 0;
}


/// ** 2D memory allocation function ** ///
char **malloc2d(int r, int c){
    int i, j;
    char **mat;

    mat = (char**) malloc (r*sizeof(char*));
    if (mat == NULL){
        fprintf(stderr, "memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for (i=0; i<r; i++){
        mat[i] = (char*) malloc (c*sizeof(char));
        if (mat[i] == NULL){
            fprintf(stderr, "memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
    }
    for (i=0; i<r; i++){
        for (j=0; j<c; j++){
            mat[i][j] = ' ';
        }
    }
    return mat;
}


/// ** free 2D allocated memory ** ///
char **free2d(char **mat, int r){
    int i;
    for (i=0; i<r; i++){
        free (mat[i]);
    }
    free (mat);
    return NULL;
}


/// ** find function ** ///
void find (char *word, char **matrixIn, char **matrixOut, int R, int C){
    int i, j;

    for (i=0; i<R; i++) {
        for (j=0; j<C; j++) {
#if CHECK_VERSION
            if (matrixIn[i][j]==word[0] && find_all(i, j, word, matrixIn, matrixOut, R, C)){
#else
                if (find_all(i, j, word, matrixIn, matrixOut, R, C)) {
#endif
                    return;
                }
            }
        }
}
int find_all(int row, int col, char *word, char **mIn, char **mOut, int R, int C){
        char flag;
        int r, c, i, j;
        int offset[2][8] = { {0, -1, -1, -1, 0, 1, 1, 1},
                             {1, 1, 0, -1, -1, -1, 0, 1}};
        for (i=0; i<8; i++){
            flag = 1;
#if CHECK_VERSION
            for (j=1; j<strlen(word) && flag; j++){
#else
                for (j=0; j<strlen(word) && flag; j++){
#endif
                    r = row + j * offset[0][i];
                    c = col + j * offset[1][i];

                    if (r<0 || r>=R || c<0 || c>=C || mIn[r][c]!=word[j]){
                        flag = 0;
                    }
                }
                if (flag == 1){
                    for (j=0; j<strlen(word); j++){
                        mOut[row+j*offset[0][i]][col+j*offset[1][i]] = word[j];
                    }
                    return 1;
                }
        }
        return 0;
    }
