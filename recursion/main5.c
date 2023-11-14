// binary search
#include <stdio.h>
#define MAX 10
#define WANNAFIND 101

int bin_search (int v[], int l, int r, int k){
    int c;
    if (l > r){
        return -1;
    }
    c = (l + r) / 2;

    if (k < v[c])
        return bin_search(v, l, c-1, k);
    if (k > v[c])
        return bin_search(v, c+1, r, k);
    return c;
}


int main(){
    int v[MAX] = {0};

    for (int i=0; i<MAX; i++){
        v[i] = i+100;
        printf("%d ", v[i]);
    }

    int binary = bin_search(v, 0, 9, WANNAFIND);

    printf("\n%d", binary);
