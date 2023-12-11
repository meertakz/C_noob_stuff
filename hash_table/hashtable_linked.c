#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define MAX_NAME 256
#define TABLE_SIZE 10


typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next;
} person;


person *hash_table[TABLE_SIZE];


unsigned int hash (char *name){
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i=0; i<length; i++){
        hash_value += name[i];
        hash_value *= name[i];
        hash_value = hash_value % TABLE_SIZE;
    }
    return hash_value;
}


void init_hash_table(){
    for (int i=0; i<TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    // table is empty
}


void print_table(){
    printf("--start\n");
    for (int i=0; i<TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t ", i);
            person *tmp = hash_table[i];
            while (tmp != NULL) {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("--end\n\n");
}


bool hash_table_insert(person *p){
    if (p == NULL){
        return false;
    }
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;

    return true;
}


person *hash_table_lookup (char *name){
    int index = hash(name);
    person *tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        tmp = tmp->next;
    }
    return tmp;
}


person *hash_table_delete (char *name){
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0){
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL){
        //deleting the head
        hash_table[index] = tmp->next;
    } else{
        prev->next = tmp->next;
    }
    return tmp;
}




int main(){

    init_hash_table();
    print_table();


    printf("<<<insertions happening...>>>\n\n");
    person jacob = {.name="Jacob", .age=256};
    person kate = {.name="Kate", .age=27};
    person matt = {.name="Matt", .age=14};
    person sarah = {.name="Sarah", .age=22};
    person edna = {.name="Edna", .age=19};
    person maren = {.name="Maren", .age=34};
    person eliza = {.name="Eliza", .age=29};
    person robert = {.name="Robert", .age=12};
    person jane = {.name="Jane", .age=21};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&matt);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane);



    print_table();

    printf("<<<deleting \"Sarah\"...>>>\n\n");
    hash_table_delete("Sarah");


    printf("______searching in the hash table______\n");
    person *tmp = hash_table_lookup("Matt");
    if (tmp == NULL){
        printf("not found\n");
    } else {
        printf("found %s\n", tmp->name);
    }


    tmp = hash_table_lookup("I_STILL_DONT_EXIST");
    if (tmp == NULL){
        printf("not found\n");
    } else {
        printf("found %s\n", tmp->name);
    }



    tmp = hash_table_lookup("Sarah");
    if (tmp == NULL){
        printf("not found\n");
    } else {
        printf("found %s\n", tmp->name);
    }
    printf("_______________________________________\n\n");

    print_table();
    return 0;
}
