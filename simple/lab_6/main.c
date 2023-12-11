#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

#define EMPTY ' '
#define START '@'
#define STOP  '#'
#define PATH  '$'

const int xOff[4] = { 0, 1, 0, -1};
const int yOff[4] = {-1, 0, 1,  0};

/* prototypes */
void display (char **maze, int nr);
int move_recur (char **mazeCurr, int stepCurr, char **mazeBest, int stepBest, int nr, int nc, int row, int col);
FILE *util_fopen (char *name, char *mode);
void *util_malloc (int size);
char *util_strdup (char *src);

/* main */
int main(int argc, char *argv[])
{
    int r=-1, c=-1, i, j, nr, nc, step;
    char **mazeCurr, **mazeBest;
    char line[MAX];
    FILE *fp;

    if (argc < 2) {
        printf("Error: missing parameter.\n");
        printf("Run as: %s <maze_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = util_fopen(argv[1], "r");
    fgets(line, MAX, fp);
    sscanf(line, "%d %d", &nr, &nc);
    mazeCurr = (char **)util_malloc(nr * sizeof(char *));
    mazeBest = (char **)util_malloc(nr * sizeof(char *));
    for (i=0; i<nr; i++) {
        fgets(line, MAX, fp);
        mazeCurr[i] = util_strdup(line);
        mazeBest[i] = util_strdup(line);
        for (j=0; j<nc; j++) {
            if (mazeCurr[i][j] == START) {
                mazeCurr[i][j] = ' ';
                r = i;
                c = j;
            }
        }
    }

    if (r<0 || c<0) {
        printf("Error: no startig position found!\n");
        exit(EXIT_FAILURE);
    }
    step = move_recur(mazeCurr, 0, mazeBest, nr*nc, nr, nc, r, c);
    if (step > 0) {
        printf("Solution:\n");
        mazeBest[r][c] = START;
        display(mazeBest, nr);
    } else {
        printf("NO solution found!\n");
    }

    for (r=0; r<nr; r++) {
        free(mazeCurr[r]);
        free(mazeBest[r]);
    }
    free(mazeCurr);
    free(mazeBest);
    return EXIT_SUCCESS;
}

/*
 *  recursively move the player up to the maze exit
 *  find the best solution
 */
int move_recur(char **mazeCurr, int stepCurr, char **mazeBest, int stepBest,
               int nr, int nc, int row, int col)
{
    int k, r, c;

    /* Avoid stopping recursion to find ALL solutions */
    if (stepCurr >= stepBest) {
        return stepBest;
    }
    if (mazeCurr[row][col] == STOP) {
        /* STOP recurring to print-out only ONE solution */
        /* Print all matrices to have ALL solutions */
        if (stepCurr < stepBest) {
            stepBest = stepCurr;
            for (r=0; r<nr; r++) {
                for (c=0; c<nc; c++) {
                    mazeBest[r][c] = mazeCurr[r][c];
                }
            }
        }
        return stepBest;
    }
    if (mazeCurr[row][col] != EMPTY) {
        return stepBest;
    }

    mazeCurr[row][col] = PATH;
    for (k=0; k<4; k++) {
        r = row + xOff[k];
        c = col + yOff[k];
        if (r>=0 && r<nr && c>=0 && c<nc) {
            stepBest = move_recur(mazeCurr, stepCurr+1, mazeBest, stepBest, nr, nc, r, c);
        }
    }
    mazeCurr[row][col] = EMPTY;

    return stepBest;
}

/*
 *  write the maze scheme on screen
 */
void display(char **maze, int nr)
{
    int i;

    for (i=0; i<nr; i++) {
        printf("%s", maze[i]);
    }
}

/*
 *  fopen (with check) utility function
 */
FILE *util_fopen(char *name, char *mode)
{
    FILE *fp=fopen(name, mode);
    if (fp == NULL) {
        printf("Error opening file %s.\n", name);
        exit(EXIT_FAILURE);
    }
    return fp;
}

/*
 *  malloc (with check) utility function
 */
void *util_malloc(int size)
{
    void *ptr=malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/*
 *  strdup (with check) utility function
 */
char *util_strdup(char *src)
{
    char *dst=strdup(src);
    if (dst == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    return dst;
}
