#include <stdio.h>


void printDate(char *date)
{
    int d,m,y;
    char calendar[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};

    int n = sscanf(date,"%2d-%2d-%4d",&d,&m,&y);

    if (n!=3 || d<1 || d>30 || m<1 || m>12 || y<0)
        printf("Error date format!");
    else
        printf("%d %s %d",d,calendar[m-1],y); }

        
int main() 
{
    printDate("21-05-1998");
}
