#include <stdio.h>
#include <string.h>

char* findSubstring(char s1[], char s2[])
{
    int l1,l2,i;
    l1 = strlen(s1);
    l2 = strlen(s2);
  
    for (i=0; i<=l1-l2;i++)
    {
        if (strncmp(s1+i,s2,l2)==0)
            return s1+i;
    }
    return NULL;
}

int main()
{
    printf("%s", findSubstring("substring","str"));
}
