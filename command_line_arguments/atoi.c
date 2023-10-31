#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc !=3)
    {
        printf("two args needed");
        exit(1);
    }
    int lower = atoi(argv[1]);
    int higher = atoi(argv[2]);

    for (int i=lower; i<=higher; i++)
    {
        printf("%d\n",i);
    }
    return 0;
}
