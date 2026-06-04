#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Array to store column positions. x[i] = j means Queen at row i is in column j.
int x[20];

/**
 * Checks if a queen can be safely placed at the specified row and column.
 * Returns 1 if safe, 0 otherwise.
 */
int place(int row, int column) {
    for (int i = 1; i < row; i++) {
        // Check column conflict and diagonal conflict
        if (x[i] == column || abs(x[i] - column) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

/**
 * Backtracking function to place queens and print solutions.
 */
void queens(int row, int n) {
    static int solution_count = 0;

    for (int column = 1; column <= n; column++) {
        if (place(row, column)) {
            x[row] = column; // Place the queen

            if (row == n) {
                // Base case: All queens placed, print the solution board
                printf("\nSolution %d:\n", ++solution_count);
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (x[i] == j) {
                            printf(" Q ");
                        } else {
                            printf(" . ");
                        }
                    }
                    printf("\n");
                }
            } else {
                // Recursive case: Move to the next row
                queens(row + 1, n);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of Queens: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 20) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n == 2 || n == 3) {
        printf("No solutions exist for %d-Queens.\n", n);
    } else {
        // Start the algorithm at row 1
        queens(1, n);
    }

    return 0;
}
