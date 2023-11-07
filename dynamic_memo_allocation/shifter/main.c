#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ======> 100 + '\n' + '\0'
#define MAX 102


/// ** function prototypes ** ///
void search1(char[], char[]);
void check1(char**, char[], int);
void search2(char[], char[]);
void check2(char(*)[MAX], char[], int);



/// ** main ** ///
int main(int argc, char* argv[]){
    if (argc < 3){
        fprintf(stderr, "error: missing parameter/s\n");
        fprintf(stderr, "run as: %s <keyword> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    fprintf(stdout, "solution 1:\n");
    search1(argv[2], argv[1]);
    fprintf(stdout, "solution 2:\n");
    search2(argv[2], argv[1]);
    return EXIT_SUCCESS;
}



/// ** search keyword in the text file ** ///
void search1(char name[], char word[]){
    char **monitor, line[MAX];
    int i, row, length;
    FILE *fp;

    fp = fopen(name, "r");
    if (fp == NULL) {
        fprintf(stderr, "file open error (%s)\n", name);
        exit(EXIT_FAILURE);
    }

    length = strlen(word);
    monitor = (char**) malloc (length*sizeof(char*));
    if (monitor == NULL){
        fprintf(stderr, "memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for (i=0; i<length; i++){
        monitor[i] = NULL;
    }
    row = 0;
    while (fgets(line, MAX, fp) != NULL){
        // shift previously read lines
        free (monitor[0]);
        for (i=0; i<length-1; i++){
            monitor[i] = monitor[i+1];
        }
        monitor[i] = strdup(line);
        if (monitor[i] == NULL){
            fprintf(stderr, "memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        if (++row >= length){
            check1(monitor, word, row);
        }
    }
    fclose(fp);
    for (i=0; i<length; i++){
        free(monitor[i]);
    }
}



/// ** check for keyword in a text piece ** ///
void check1(char **monitor, char word[], int row){
    int i, j, equal, min=0, length;
    length=strlen(word);
    // search for the shortest line
    for (i=1; i<length; i++){
        if (strlen(monitor[i]) < strlen(monitor[min])){
            min = i;
        }
    }
    // search on all columns
    for (j=0; j<strlen(monitor[min]); j++){
        equal=1;
        for (i=0; i<length && equal==1; i++){
            if (word[i]!=monitor[i][j]){
                equal=0;
            }
        }
        if (equal == 1){
            fprintf(stdout, "word \"%s\" found in ", word);
            fprintf(stdout, "row %d, char %d\n", row-length+1, j+1);
        }
    }
}



/// ** search the keyword in the whole text file ** ///
void search2(char name[], char word[]){
    char (*monitor)[MAX];
    int row, length;
    FILE *fp;

    fp = fopen(name, "r");
    if (fp == NULL){
        fprintf(stderr, "file open error (%s)\n", name);
        exit(EXIT_FAILURE);
    }
    length = strlen(word);
    monitor = (char (*) [MAX]) malloc (length*sizeof(char[MAX]));
    if (monitor == NULL) {
        fprintf(stderr, "memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    row = 0;
    while (fgets(monitor[row%length], MAX, fp)!=NULL){
        if (++row >= length){
            check2(monitor, word, row);
        }
    }
    fclose(fp);
    free(monitor);
}



/// ** check for keyword in a text piece ** ///
void check2(char (*monitor)[MAX], char word[], int row){
    int i, j, equal, min=0, length;
    length = strlen(word);
    // search for the shortest line
    for (i=1; i<length; i++){
        if (strlen(monitor[i]) < strlen(monitor[min])){
            min = i;
        }
    }
    // search all columns
    for (j=0; j<strlen(monitor[min]); j++){
        equal = 1;
        for (i=0; i<length && equal==1; i++){
            if (word[i] != monitor[(row+i)%length][j]){
                equal = 0;
            }
        }
        if (equal == 1){
            fprintf(stdout, "word \"%s\" found in ", word);
            fprintf(stdout, "row %d, char %d\n", row-length+1, j+1);
        }
    }
}
