// string reverser
#include <stdio.h>
#define max 15


void reverse_print (char *s){
    if (*s == '\0'){
        return;
    }
    reverse_print(s+1);
    printf("%c", *s);
}


int main(){
    char str[max+1];
    printf("input string: ");
    scanf("%s", str);
    printf("reverse string is --> ");
    reverse_print(str);
}
