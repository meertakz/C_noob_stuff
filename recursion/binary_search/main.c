#include <stdio.h>


void show(int v[], int l, int r) {
    int i, c;
    printf("v = ");
    for (i = l; i <= r; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    if (l >= r) {
        return;
    }
    c = (l + r) / 2; // Fix the calculation of the middle index
    show(v, l, c);
    show(v, c + 1, r);
}


int main() {
    int arr[8] = {0};
    int m = 1;

    for (int i = 0; i < 8; i++) {
        arr[i] = m;
        m++;
    }
    show(arr, 0, 7);
    return 0;
}
