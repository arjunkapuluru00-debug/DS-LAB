#include <stdio.h>

int main() {
    int degree, i;
    int poly1[20], poly2[20], sum[20];

    printf("Enter the highest degree of the polynomial: ");
    scanf("%d", &degree);

    // Read first polynomial
    printf("\nEnter coefficients of first polynomial:\n");
    for (i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    // Read second polynomial
    printf("\nEnter coefficients of second polynomial:\n");
    for (i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    // Add polynomials
    for (i = 0; i <= degree; i++) {
        sum[i] = poly1[i] + poly2[i];
    }

    // Display result
    printf("\nResultant Polynomial:\n");
    for (i = degree; i > 0; i--) {
        if (sum[i] != 0)
            printf("%dx^%d + ", sum[i], i);
    }
    printf("%d\n", sum[0]);

    return 0;
}
