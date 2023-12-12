#include <stdio.h>
#include <stdlib.h>


/* a single node */
typedef struct item {
    int data;
    int key;
} item_t;


/* hash table struct */
typedef struct hashTable {
    int count;
    int size;
    item_t *deletedItem;
    item_t **array;
} hashTable_t;


/* function declarations */
item_t *newItem(int, int);
void freeItem(item_t *);
hashTable_t *newHashTable(int);
void freeHashTable(hashTable_t *);
int hasItem(hashTable_t *, int);
void display(hashTable_t *);
int isFull(hashTable_t *);
int hashCode(int, int);
int insert(hashTable_t *, int, int);
int search(hashTable_t *, int);
item_t *h_remove(hashTable_t *, int);
int input(void);


/* main program */
int main() {
    int itemIndex = -1;
    item_t *item = NULL;

    int size;
    do {
        printf("==================\n");
        printf(">please enter the\n>size of the hash\n>table          #");
        size = input();
    } while (size < 1);

    hashTable_t *table = newHashTable(size);

    while (1) {
        printf("==================\n");
        printf("0 --> @fill table\n");
        printf("1 --> insert item\n");
        printf("2 --> delete item\n");
        printf("3 --> search item\n");
        printf("4 --> show  table\n");
        printf("5 --> empty table\n");
        printf("6 --> # e x i t #\n");
        printf("==================\n");
        printf("enter #");
        int u_input = input();

        switch (u_input) {
            case 0: {
                for (int i = 0; i < size; i++) {
                    insert(table, i, i);
                }
                printf("==================\n");
                printf("@ filling success.     <<<\n");
                break;
            }
            case 1: {
                printf("==================\n");
                printf("enter the key #");
                int k = input();
                printf("enter the data #");
                int v = input();
                insert(table, k, v);
                break;
            }
            case 2: {
                printf("==================\n");
                printf("enter the key #");
                int k = input();
                h_remove(table, k);
                break;
            }
            case 3: {
                printf("==================\n");
                printf("enter the key #");
                int k = input();
                printf("==================\n");
                itemIndex = search(table, k);
                if (itemIndex != -1) {
                    item = table->array[itemIndex];
                    printf("item (%d,%d) found.     <<<\n", item->key, item->data);
                } else {
                    printf("item not found !     <<<\n");
                }
                break;
            }
            case 4: {
                printf("==================\n");
                display(table);
                break;
            }
            case 5: {
                printf("==================\n");
                for (int i = 0; i < size; i++) {
                    h_remove(table, i);
                }
                printf("hash table reset !     <<<\n");
                break;
            }
            case 6: {
                printf("==================\n");
                printf(". . .good-bye. . .     <<<\n");
                printf("==================\n");
                freeHashTable(table);
                exit(0);
            }
            default: {
                printf("Invalid choice. Try again.     <<<\n");
            }
        }
    }
}

/*
 * functions
 */

item_t *newItem(int key, int data) {
    item_t *result = malloc(sizeof(item_t));
    result->key = key;
    result->data = data;
    return result;
}


void freeItem(item_t *item) {
    if (item != NULL)
        free(item);
}


hashTable_t *newHashTable(int size) {
    hashTable_t *result = malloc(sizeof(hashTable_t));
    result->count = 0;
    result->size = size;
    result->deletedItem = newItem(-1, -1);
    result->array = malloc(sizeof(item_t *) * size);
    return result;
}


void freeHashTable(hashTable_t *table) {
    if (table != NULL) {
        for (int i = 0; i < table->size; i++) {
            item_t *item = table->array[i];
            if (item != NULL && item != table->deletedItem)
                free(item);
        }
        free(table->array);
        freeItem(table->deletedItem);
        free(table);
    }
}


int hasItem(hashTable_t *table, int index) {
    return table->array[index] != NULL && table->array[index] != table->deletedItem;
}


void display(hashTable_t *table) {
    for (int i = 0; i < table->size; i++) {
        if (hasItem(table, i)) {
            item_t *item = table->array[i];
            printf("%d) (%d,%d)\n", i, item->key, item->data);
        } else {
            printf("%d) empty\n", i);
        }
    }
}


int isFull(hashTable_t *table) {
    return table->count == table->size;
}


int hashCode(int key, int size) {
    return key % size;
}


int insert(hashTable_t *table, int key, int data) {
    int result = 0;
    if (isFull(table)) {
        printf("==================\n");
        printf(". . . errore . . .\n");
        printf("hash table is full\n");
    } else {
        item_t *item = newItem(key, data);
        int index = hashCode(key, table->size);

        while (hasItem(table, index))
            index = hashCode(index + 1, table->size);
        table->array[index] = item;
        table->count++;
    }

    return result;
}


int search(hashTable_t *table, int key) {
    int result = -1;
    int index = hashCode(key, table->size);
    int counter = table->size;

    while (table->array[index] != NULL && counter > 0) {
        if (table->array[index]->key == key) {
            result = index;
            break;
        }
        counter--;
        index = hashCode(index + 1, table->size);
    }

    return result;
}


item_t *h_remove(hashTable_t *table, int key) {
    item_t *result = NULL;
    int index = search(table, key);

    if (index != -1) {
        result = table->array[index];
        table->array[index] = table->deletedItem;
        table->count--;
    }
    return result;
}


int input(void) {
    int number;
    char buffer[100];
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            exit(1);
        }
        if (sscanf(buffer, "%d", &number) == 1) {
            break;
        } else {
            printf("==================\n");
            printf("Invalid input !!!\n#");

        }
    }
    return number;
}
