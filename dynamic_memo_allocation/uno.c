#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, n3, i, *ptr;

    // user input
    printf("enter size :");
    scanf("%d",&n1);
    /// malloc ///
    ptr = (int*)malloc(n1*sizeof(int));
    printf("==============\n");
    // print addresses
    for (i=0;i<n1;i++)
        printf("%p \n", ptr+i);
    printf("==============\n\n");
    
    
    // user input
    printf("enter new size :");
    scanf("%d",&n2);
    /// realloc ///
    ptr = realloc(ptr,n2*sizeof(int));
    printf("==============\n");
    // print addresses
    for (i=0;i<n2;i++)
        printf("%p \n", ptr+i);
    printf("==============\n\n");

    
    // user input
    printf("enter calloc size :");
    scanf("%d",&n3);
    /// calloc ///
    printf("==============\n");
    ptr = (int*)calloc(n3, sizeof(int));
    // print addresses
    for (i=0;i<n3;i++)
        printf("%p \n", ptr+i);
    printf("==============\n\n");

    
    // check for error
    if (ptr == NULL)
        printf(stderr, "memory allocation error\n");

    /// free ///
    free(ptr);

}
