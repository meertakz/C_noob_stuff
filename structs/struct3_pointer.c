#include <stdio.h>

struct str {
    int x;
    int y;
};

int main()
{
    struct str a = {0,1};
    struct str *ptr = &a;

    // two different ways to access //
    printf("%d %d\n", ptr->x, (*ptr).y);

    return 0;
}
