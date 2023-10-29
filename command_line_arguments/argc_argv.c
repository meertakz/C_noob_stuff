#include <stdio.h>

// argc is the number of arguments
// argv is an array of strings holding each argument

int main (int argc, char * argv[])
{
    // print number of arguments passed to our program
    printf("argc: %d\n", argc);
    for (int i=0; i<argc; i++)
        printf("argv[%d] ==> %s\n", i, argv[i]);
    return 0;
}


