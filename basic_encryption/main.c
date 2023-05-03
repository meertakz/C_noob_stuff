//
// Created by Zeki Mert Aköz on 2.05.2023.
//
#include <stdio.h>
#include <string.h>

#define FILENAME "text_files/dictionary.txt"
#define FILENAME_2 "text_files/source.txt"
#define FILENAME_3 "text_files/output.txt"

int main(void)
{

    int lines;
    char replace[100][100], word[100][100];
    //// open dictionary file
    FILE *dictionary=fopen(FILENAME,"r");

    //// scan the first int
    fscanf(dictionary, "%d", &lines);

    //// fill up the dictionary
    for (int i=0;i<lines;i++)
    {
        fscanf(dictionary,"%s %s", replace[i], word[i]);
    }
    fclose(dictionary);

    //// scan the source.txt
    FILE *input=fopen(FILENAME_2, "r");
    char strings[100][100];
    int n=0;

    //// fill up strings array
    while (fscanf(input,"%s", strings[n])!=EOF)
    {
        n++;
    }
    fclose(input);

    //// transformation
    for (int j=0; j<n; j++)
    {
        for (int k=0; k<lines; k++)
        {
            if (strstr(strings[j], word[k])!=0)
            {
                memcpy(strstr(strings[j], word[k]), replace[k], strlen(word[k]));

            }
        }
    }
    //// open output file and write the encrypted version
    FILE *output=fopen(FILENAME_3, "w");
    for (int g=0; g<n; g++)
    {
        fprintf(output,"%s ", strings[g]);
        if ((g>1)&&((g+1)%4==0))
        {
            fprintf(output,"\n");
        }
    }
    fclose(output);
}
