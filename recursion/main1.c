// find maximum in an array by recursion
#include <stdio.h>


int max(int v[], int l, int r) {
    int c, m1, m2;

    if (l >= r) {
        return v[l];
    }
    c = (l + r) / 2; // Fix the calculation of the middle index
    m1 = max(v, l, c);
    m2 = max(v, c + 1, r);

    if (m1>m2){
        return m1;
    }else{
        return m2;
    }
}


int main() {
    int arr[8] = {0,34, 24, 1, 999, 2, 9, -3};

    int maxi = max(arr, 0, 7);
    fprintf(stdout, "%d", maxi);
    return 0;
}
