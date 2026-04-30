#include <stdio.h>

void sortItems(int value[], int weight[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double r1 = (double)value[i] / weight[i];
            double r2 = (double)value[j] / weight[j];
            if (r1 < r2) {
                // swap values
                int tempVal = value[i];
                value[i] = value[j];
                value[j] = tempVal;

                // swap weights
                int tempWt = weight[i];
                weight[i] = weight[j];
                weight[j] = tempWt;
            }
        }
    }
}

double fractionalKnapsack(int value[], int weight[], int n, int capacity) {
    sortItems(value, weight, n);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= capacity) {
            currentWeight += weight[i];
            totalValue += value[i];
        } else {
            int remain = capacity - currentWeight;
            totalValue += value[i] * ((double)remain / weight[i]);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int value[n], weight[n];

    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &value[i], &weight[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(value, weight, n, capacity);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
