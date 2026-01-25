#include <stdio.h>

struct Car {
    int carID;
    char model[50];
    float ratePerDay;
};

int main() {
    struct Car c[3];
    int days;
    float totalCost;

    for (int i = 0; i < 3; i++) {
        scanf("%d", &c[i].carID);
        scanf("%s", c[i].model);
        scanf("%f", &c[i].ratePerDay);
    }

    scanf("%d", &days);

    for (int i = 0; i < 3; i++) {
        totalCost = c[i].ratePerDay * days;
        printf("Car ID: %d\n", c[i].carID);
        printf("Model: %s\n", c[i].model);
        printf("Total Rental Cost: %.2f\n", totalCost);
    }

    return 0;
}
