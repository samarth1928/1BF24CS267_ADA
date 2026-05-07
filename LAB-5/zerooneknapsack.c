#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("Maximum value in Knapsack = %d\n", dp[n][W]);

    int res = dp[n][W];
    int w = W;
    printf("Items selected (index starting from 1): ");
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i-1][w])
            continue;
        else {
            printf("%d ", i);
            res -= val[i-1];
            w -= wt[i-1];
        }
    }
    printf("\n");
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    knapsack(W, wt, val, n);

    return 0;
}
