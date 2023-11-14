// determinant of a matrix
#include <stdio.h>
#include <math.h>

#define MAX 10

// Function to calculate the determinant of a 2x2 matrix
int det2x2(int m[][MAX]) {
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

// Function to calculate the minor of a matrix by excluding the specified row and column
void minor(int m[][MAX], int row, int col, int size, int result[][MAX]) {
    int i, j;
    int p = 0, q = 0;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i != row && j != col) {
                result[p][q++] = m[i][j];

                if (q == size - 1) {
                    q = 0;
                    p++;
                }
            }
        }
    }
}

// Function to calculate the determinant of an n x n matrix
int det(int m[][MAX], int n) {
    int sum, c;
    int tmp[MAX][MAX];
    sum = 0;

    if (n == 2)
        return det2x2(m);

    for (c = 0; c < n; c++) {
        minor(m, 0, c, n, tmp);
        sum = sum + m[0][c] * pow(-1, c) * det(tmp, n - 1);
    }
    return sum;
}

int main() {
    int matrix[MAX][MAX];
    int n, i, j;

    // Get the order of the matrix from the user
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);

    // Get the elements of the matrix from the user
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate and print the determinant
    int determinant = det(matrix, n);
    printf("Determinant: %d\n", determinant);

    return 0;
}
