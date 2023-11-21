#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_R 255+1
#define MAX_C  16+1
#define MAX_D  10+1
#define MAX    21


typedef struct employee {
    char *name;
    char id[MAX_C];
    char date[MAX_D];
    int salary;
    struct employee *left;
    struct employee *right;
} employee_t;


/* declarations */
employee_t *readFile (employee_t *, char []);
void write (employee_t *, char *, char *);


/* main */
int main (int argc, char * argv[])
{
    employee_t *head, *tmp1, *tmp2;

    if (argc!=4) {
        fprintf(stderr, "Run as: <pgrmName> <inFile> <name> <commands>\n");
        exit(1);
    }

    head = NULL;
    head = readFile (head, argv[1]);
    write (head, argv[2], argv[3]);

    tmp1 = head;
    while (tmp1!=NULL) {
        free (tmp1->name);
        tmp2 = tmp1->right;
        free (tmp1);
        tmp1 = tmp2;
    }

    return (EXIT_SUCCESS);
}


/* read the file into a struct */
employee_t * readFile (employee_t *head, char *fileIn)
{
    FILE *input;
    char riga[MAX_R], name[MAX];
    employee_t *tmpPtr;

    input = fopen(fileIn, "r");
    if (input == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    while (fgets(riga, MAX_R, input)!=NULL){
        tmpPtr = (employee_t *) malloc (sizeof (employee_t));
        if (tmpPtr==NULL){
            printf("Allocation Error.\n");
            exit (EXIT_FAILURE);
        }
        sscanf(riga, "%s %s %s %d",
               name, tmpPtr->id, tmpPtr->date, &tmpPtr->salary);
        tmpPtr->name = (char *) malloc ((strlen(name)+1)*sizeof(char));
        sprintf (tmpPtr->name, "%s", name);
        tmpPtr->right = head;
        tmpPtr->left = NULL;
        if (head!=NULL) {
            head->left = tmpPtr;
        }
        head = tmpPtr;
    }
    fclose (input);
    return (head);
}


/* write output */
void write (employee_t *headPtr, char *name, char *command)
{
    employee_t *tmpPtr;
    int i;

    for (tmpPtr=headPtr; tmpPtr!=NULL; tmpPtr=tmpPtr->right) {
        if (strcmp(tmpPtr->name, name) == 0 ) {
            break;
        }
    }

    if (tmpPtr==NULL) {
        exit(1);
    }

    fprintf (stdout, "%s %s %s %d\n",
             tmpPtr->name, tmpPtr->id, tmpPtr->date, tmpPtr->salary);

    for (i=0; i<strlen(command); i++) {
        if (command[i] == '+') {
            if (tmpPtr->right!=NULL) {
                tmpPtr = tmpPtr->right;
            }
        } else {
            if (tmpPtr->left!=NULL) {
                tmpPtr = tmpPtr->left;
            }
        }
        fprintf (stdout, "%s %s %s %d\n",
                 tmpPtr->name, tmpPtr->id, tmpPtr->date, tmpPtr->salary);
    }
}
