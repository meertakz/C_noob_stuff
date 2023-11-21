#include <stdio.h>

struct employee {
    char *name;
    int age;
    int salary;
};

int manager()
{
    struct employee manager;
    manager.name = "dick";
    manager.age = 27;

    if (manager.age>30)
        manager.salary=60000;
    else
        manager.salary=55000;

    return manager.salary;
}

int main()
{
    struct employee emp1;
    struct employee emp2;
    emp1.name = "joe";
    emp1.age = 28;
    emp1.salary = 40000;
    emp2.name = "jane";
    emp2.age = 23;
    emp2.salary = 35000;


    printf("manager 's salary ==> %d\n", manager());
    printf("%s\t\t's salary ==> %d\n", emp1.name, emp1.salary);
    printf("%s\t's salary ==> %d\n", emp2.name, emp2.salary);

    return 0;
}
