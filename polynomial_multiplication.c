#include <stdio.h>

int main() {
    int deg1, deg2, i, j;
    int poly1[20], poly2[20], result[40];

    // Initialize result array
    for (i = 0; i < 40; i++)
        result[i] = 0;

    // Read degree of first polynomial
    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);

    printf("Enter coefficients of first polynomial:\n");
    for (i = deg1; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    // Read degree of second polynomial
    printf("\nEnter degree of second polynomial: ");
    scanf("%d", &deg2);

    printf("Enter coefficients of second polynomial:\n");
    for (i = deg2; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    // Polynomial multiplication
    for (i = 0; i <= deg1; i++) {
        for (j = 0; j <= deg2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    // Display result
    printf("\nResultant Polynomial after multiplication:\n");
    for (i = deg1 + deg2; i > 0; i--) {
        if (result[i] != 0)
            printf("%dx^%d + ", result[i], i);
    }
    printf("%d\n", result[0]);

    return 0;
}
