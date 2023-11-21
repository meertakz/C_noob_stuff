// simple factorial by recursion
#include <stdio.h>

long int fact (long int n);

int main(void){
    long int n;
    fprintf(stdout, "welcome to factorial calculator\n");
    printf("____________________enter n = ");
    scanf("%ld", &n);
    printf("%d ! = %d\n", n, fact(n));
}

long int fact (long int n){
    long int f;
    if (n == 0){
        return 1;
    }
    f = fact(n-1);
    return (n * f);
}
