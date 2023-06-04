#include <stdio.h>
#include <string.h>

char* findSequence(char* word, char ch, int n)
{
    int i,count = 0;

    for (i=0;i<=strlen(word)-n;i++)
    {
        if (word[i]==ch)
        {
            count ++;
            if (count==n)
                return(word+i-n+1);
        }
        else
            count = 0;
    }
    return NULL;
}


int main()
{
    printf("%s",findSequence("Pasticcio",'c',2));
}
