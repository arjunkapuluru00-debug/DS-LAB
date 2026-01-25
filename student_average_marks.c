#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float totalMarks;
};

int main() {
    struct Student s[2];
    float average;

    for (int i = 0; i < 2; i++) {
        scanf("%s", s[i].name);
        scanf("%d", &s[i].age);
        scanf("%f", &s[i].totalMarks);
    }

    for (int i = 0; i < 2; i++) {
        printf("Name: %s\n", s[i].name);
        printf("Age: %d\n", s[i].age);
        printf("Total Marks: %.2f\n", s[i].totalMarks);
    }

    average = (s[0].totalMarks + s[1].totalMarks) / 2;
    printf("Average Total Marks: %.2f\n", average);

    return 0;
}
