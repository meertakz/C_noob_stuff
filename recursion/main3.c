// fibonacci (low input)
#include <stdio.h>

long int fib(long int n);

int main(void){
    long int n;
    fprintf(stdout, "input n = ");
    scanf("%ld", &n);
    fprintf(stdout, "fibonacci of %d is %d\n", n, fib(n));
}

long int fib (long int n){
    long int f1, f2;
    if (n==0 || n==1){
        return n;
    }
    f1 = fib(n-2);
    f2 = fib(n-1);
    return (f1+f2);
}
