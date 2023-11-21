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


/* main */
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


/* add word function */
void add_word (wordT **headP, char *word){
    wordT *current = *headP;

    while (current != NULL){
        if (strcmp(current->word, word) == 0){
            // word already in the list
            current->freq++;
            return;
        }
        current = current->next;
    }
    // if it is not existent, add new
    wordT *newWord = (wordT *) malloc (sizeof(wordT));
    if (newWord == NULL){
        fprintf(stderr, "memory allocation failed\n");
        exit(1);
    }
    newWord->length = 10 - strlen(word);
    newWord->word = strdup(word);
    newWord->freq = 1;
    newWord->next = *headP;
    *headP = newWord;
}


/* lowercase & add to struct */
void lower_and_add_struct (FILE *fp, wordT **headP){
    char word[MAX_SIZE];

    while (fscanf(fp, "%s", word) == 1){
        // convert to lowercase
        for (int i=0; word[i]; i++){
            word[i] = tolower(word[i]);
        }
        // add to struct function
        add_word(headP, word);
    }
}


wordT *get_text (FILE *fp){
    wordT *headP = NULL;
    lower_and_add_struct(fp, &headP);
    return headP;
}


/* free memory */
void free_list (wordT *head){
    while (head != NULL){
        wordT *temp = head;
        head = head->next;
        // free word
        free(temp->word);
        // free node
        free(temp);
    }
}


/* write the results to a file */
void output_results (FILE *fp, wordT *head){
    while (head != NULL){
        wordT *temp = head;
        head = head->next;


        fprintf(fp, "THE WORD <%s>", temp->word);
        for (int i=0; i<temp->length; i++){
            fprintf(fp, " ");
        }
        fprintf(fp,"APPEARED <%d> time(s)\n", temp->freq);
    }
}
