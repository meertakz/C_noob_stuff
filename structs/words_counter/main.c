#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

/* struct */
typedef struct wordS {
    char *word;
    int freq;
    int length;
    struct wordS *next;
} wordT;

/* declarations */
void add_word (wordT **, char *);
void lower_and_add_struct (FILE *, wordT **);
wordT *get_text (FILE *);
void free_list (wordT *);
void output_results (FILE *, wordT *);


int main(int argc, char *argv[]){
    if (argc != 3){
        fprintf(stderr, "error with the arguments\n%s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fpR;
    fpR = fopen(argv[1], "r");

    if (fpR == NULL){
        fprintf(stderr, "error with file opening for read\n<%s>\n", argv[1]);
        exit(1);
    }

    wordT *headP;
    headP = get_text(fpR);
    fclose(fpR);

    FILE *fpW;
    fpW = fopen(argv[2], "w");
    output_results(fpW, headP);
    fclose(fpW);

    free_list(headP);
}
