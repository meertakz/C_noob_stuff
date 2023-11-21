#include <stdio.h>

typedef struct car
{
    char engine[50];
    char fuel_type[10];
    int fuel_tank;
    int seating;
    float km;
}car;

int main()
{
    car c1 = {"120hp","gas",45,5,12};
    car c2 = {"90hp","diesel",30,4,8.5};
    car c3 = {.fuel_tank=70, .seating=6, .engine="150hp",.fuel_type="LPG", .km=15};

    printf("%s\n",c1.engine);
    printf("%s\n",c2.engine);
    printf("%s\n",c3.engine);
    return 0;
}
