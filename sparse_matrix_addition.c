#include <stdio.h>

int main() {
    int A[20][3], B[20][3], C[40][3];
    int i = 1, j = 1, k = 1;

    // Input first sparse matrix
    printf("Enter rows, columns and non-zero elements of Matrix A:\n");
    scanf("%d %d %d", &A[0][0], &A[0][1], &A[0][2]);

    printf("Enter row, column and value for Matrix A:\n");
    for (i = 1; i <= A[0][2]; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    // Input second sparse matrix
    printf("\nEnter rows, columns and non-zero elements of Matrix B:\n");
    scanf("%d %d %d", &B[0][0], &B[0][1], &B[0][2]);

    printf("Enter row, column and value for Matrix B:\n");
    for (i = 1; i <= B[0][2]; i++) {
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
    }

    // Check if addition is possible
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("\nMatrix addition not possible!");
        return 0;
    }

    // Header of result matrix
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    i = j = 1;

    // Add matrices
    while (i <= A[0][2] && j <= B[0][2]) {

        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
        else if (A[i][0] < B[j][0] ||
                (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
    }

    // Copy remaining elements
    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;

    // Display result
    printf("\nResultant Sparse Matrix after Addition:\n");
    printf("Row  Col  Value\n");
    for (i = 0; i <= C[0][2]; i++) {
        printf("%d    %d    %d\n", C[i][0], C[i][1], C[i][2]);
    }

    return 0;
}
