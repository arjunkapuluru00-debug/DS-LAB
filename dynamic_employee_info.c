#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n;
    struct Employee *emp;

    scanf("%d", &n);

    emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    for (int i = 0; i < n; i++) {
        scanf("%d", &emp[i].id);
        scanf("%s", emp[i].name);
        scanf("%f", &emp[i].salary);
    }

    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Salary: %.2f\n", emp[i].salary);
    }

    free(emp);
    return 0;
}
