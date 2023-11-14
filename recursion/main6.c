// euclidian greatest commond divisor
#include <stdio.h>

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return gcd(y, x % y);
    }
}

int main() {
    int a = 8, b = 20;
    int result = gcd(a, b);
    printf("|| %d and %d || > %d <\n", a, b, result);
    return 0;
}
