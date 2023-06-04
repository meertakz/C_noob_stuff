#include <stdio.h>
#include <stdlib.h>

int selectStudents(student list[], int n, student* listRef[], int th)
{
    int i,nSel = 0; for(i=0;i<n;i++)
        if (list[i].score>=th) listRef[nSel++] = &list[i];
    printf("%d",nSel);
    return nSel;
}

void printResults(student* listRef[], int n, char* filename) 
{
    int i;
    FILE* fp = fopen(filename,"w"); if (fp == NULL)
    {
        printf("Error file opening");
        return; }
    for (i=0;i<n;i++)
        fprintf(fp,"%7d %d\n",atoi(listRef[i]->matricola)+100,listRef[i]->score);
    fclose(fp);
}
