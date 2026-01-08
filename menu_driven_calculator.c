#include <stdio.h>

float add(float a, float b) {
    return a + b;
}
float subtract(float a, float b) {
    return a - b;
}
float multiply(float a, float b) {
    return a * b;
}
float divide(float a, float b) {
    return a / b;
}
int main() {
    int choice;
    float x, y;
    do {
        printf("\nMenu:");
        printf("\n1. Addition");
        printf("\n2. Subtraction");
        printf("\n3. Multiplication");
        printf("\n4. Division");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            scanf("%f %f", &x, &y);
        }

        switch (choice) {
            case 1:
                printf("Result = %.2f", add(x, y));
                break;
            case 2:
                printf("Result = %.2f", subtract(x, y));
                break;
            case 3:
                printf("Result = %.2f", multiply(x, y));
                break;
            case 4:
                if (y != 0)
                    printf("Result = %.2f", divide(x, y));
                else
                    printf("Division by zero not allowed");
                break;
            case 5:
                break;
            default:
                printf("Invalid choice");
        }
    } while (choice != 5);

    return 0;
}
