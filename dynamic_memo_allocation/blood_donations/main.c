#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ID 6
#define MAX_NAME 21

// struct
typedef struct{
    char id[MAX_ID];
    char surname[MAX_NAME];
    char name[MAX_NAME];
    int total_amount;
    int num_donations;
} donor_t;



// function prototypes
donor_t *donor_read (int *num_ptr);
void donation_read (donor_t *donors, int n);
int id_search (donor_t *donors, char id[MAX_ID+1], int n);
void result_display(donor_t *donors, int n);



int main(void)
{
    donor_t *donors;
    int n;

    donors = donor_read(&n);
    donation_read(donors, n);
    result_display(donors, n);

    free(donors);
    return EXIT_SUCCESS;
}



// load donor list into a dynamic array
donor_t *donor_read (int *num_ptr){
    char id[MAX_ID], name[MAX_NAME], surname[MAX_NAME];
    donor_t *donors;
    int i, n;
    FILE *fp;

    //fprintf(stdout, "donors file name    #");
    //scanf("%s", name);
    strcpy(name, "files/voluntary.txt");

    // compute number of rows
    fp = fopen(name,"r");
    if (fp==NULL){
        fprintf(stderr, "file open error (not found = <%s>)\n", name);
        exit(EXIT_FAILURE);
    }
    n = 0;
    while (fscanf(fp, "%s %*s %s %s", id, surname, name)!=EOF){
        n++;
    }
    fclose(fp);
    // allocate the dynamic array
    donors = (donor_t *)malloc(n * sizeof(donor_t));
    if (donors==NULL){
        fprintf(stderr, "memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    // read file contents
    strcpy(name, "files/voluntary.txt");
    fp = fopen(name,"r");
    if (fp==NULL){
        fprintf(stderr, "file open error (not found = <%s>)\n", name);
        exit(EXIT_FAILURE);
    }

    for (i=0; i<n; i++){
        fscanf(fp,"%s %*s %s %s", id, surname, name);
        strcpy(donors[i].id, id);
        strcpy(donors[i].surname, surname);
        strcpy(donors[i].name, name);
        donors[i].total_amount = 0;
        donors[i].num_donations = 0;
    }
    fclose(fp);

    *num_ptr = n;

    return donors;
}



// update data structure with donations file
void donation_read(donor_t *donors, int n){
    char name[MAX_NAME], id[MAX_ID];
    int i, amount;
    FILE *fp;

    //fprintf(stdout, "donations file name    #");
    //scanf("%s", name);
    strcpy(name, "files/donation.txt");

    fp = fopen(name, "r");
    if (fp==NULL){
        fprintf(stderr, "file open error (not found = <%s>)\n", name);
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s %d", id, &amount)!=EOF){
        // update donation amount
        i = id_search(donors, id, n);
        if (i>=0){
            donors[i].total_amount += amount;
            donors[i].num_donations++;
        }
    }
    fclose(fp);
}



int id_search(donor_t *donors, char id[MAX_ID+1], int n){
    int i;

    for (i=0; i<n; i++){
        if (strcmp(donors[i].id, id)==0){
            return i;
        }
    }
    return -1;
}



void result_display(donor_t *donors, int n){
    int i;

    for (i=0; i<n; i++){
        fprintf(stdout, "%s %s ", donors[i].id, donors[i].name);
        fprintf(stdout, "%s: %d", donors[i].surname, donors[i].num_donations);
        fprintf(stdout, "donations(s) - %d cc\n", donors[i].total_amount);
    }
}
