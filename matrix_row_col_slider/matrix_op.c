//
// Created by Zeki Mert Aköz on 30.04.2023.
//
#include <stdio.h>
#include <string.h>
#define FILENAME "text_files/matrix.txt"

int main() {
    int matrix[10][10];
    int row, col;

    FILE *input = fopen(FILENAME,"r");

    if (input==NULL)
    {
        printf("scusi, c'è un errore\n");
        return 1;
    }

    fscanf(input,"%d %d", &row, &col);

    //// create matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fscanf(input, "%d", &matrix[i][j]);
        }
    }
    //// print matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    char row_o_col[3], direction[10];
    int step, finaL, th_rowcol;


    //// USER INPUT
    while (strcmp(row_o_col,"end")!=0)
    {
        scanf("%s %d %s %d", row_o_col, &th_rowcol, direction, &step);

        //// ROW OPERATIONS
        if (strcmp(row_o_col, "row") == 0)
        {
            //// row to right                       >>>>>>>>>>>>>>>
            if (strcmp(direction, "right") == 0)
            {
                for (int l = 0; l < step; l++)
                {
                    finaL = matrix[th_rowcol][col - 1];
                    for (int n = col; n > 0; n--)
                    {
                        matrix[th_rowcol][n - 1] = matrix[th_rowcol][n - 2];
                    }
                    matrix[th_rowcol][0] = finaL;
                }
            }
            //// row to left                         <<<<<<<<<<<<<<
            if (strcmp(direction, "left") == 0)
            {
                for (int l = 0; l < step; l++)
                {
                    finaL = matrix[th_rowcol][0];
                    for (int n = 0; n < col; n++)
                    {
                        matrix[th_rowcol][n - 1] = matrix[th_rowcol][n];
                    }
                    matrix[th_rowcol][col - 1] = finaL;
                }
            }
        }
        //// COLUMN OPERATIONS
        if (strcmp(row_o_col,"col")==0)
        {
            //// column to up                           ^^^^^^^^^^^^^^^
            if (strcmp(direction,"up")==0)
            {
                for (int l = 0; l < step; l++)
                {
                    finaL = matrix[0][th_rowcol];
                    for (int n = 0; n < row; n++)
                    {
                        matrix[n-1][th_rowcol] = matrix[n][th_rowcol];
                    }
                    matrix[row-1][th_rowcol] = finaL;
                }
            }

            //// column to down                            vvvvvvvvvvvvvv
            if (strcmp(direction,"down")==0)
            {
                for (int l = 0; l < step; l++)
                {
                    finaL = matrix[row-1][th_rowcol];
                    for (int n = row; n > 0; n--)
                    {
                        matrix[n-1][th_rowcol] = matrix[n-2][th_rowcol];
                    }
                    matrix[0][th_rowcol] = finaL;
                }
            }
        }

        //// print matrix
        printf("CURRENT MATRIX_____\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
}
