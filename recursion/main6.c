#include <stdio.h>

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return gcd(y, x % y);
    }
}

int main() {
    int a = 20, b = 6;
    int result = gcd(a, b);
    if (result <= 1)
        printf("|| %d and %d || do not have gcd\n", a, b);
    else
        printf("|| %d and %d || > %d <\n", a, b, result);
    return 0;
}
