#include <stdio.h>
#include <stdbool.h>

void printPermutation(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int getMobile(int a[], bool dir[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        if (dir[a[i]-1] == false && i != 0) {
            if (a[i] > a[i-1] && a[i] > mobile)
                mobile = a[i];
        }
        if (dir[a[i]-1] == true && i != n-1) {
            if (a[i] > a[i+1] && a[i] > mobile)
                mobile = a[i];
        }
    }
    return mobile;
}

int getPos(int a[], int mobile, int n) {
    for (int i = 0; i < n; i++)
        if (a[i] == mobile)
            return i;
    return -1;
}

void generatePermutations(int n) {
    int a[n];
    bool dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i+1;
        dir[i] = false;
    }

    printPermutation(a, n);

    while (1) {
        int mobile = getMobile(a, dir, n);
        if (mobile == 0) break;

        int pos = getPos(a, mobile, n);

        if (dir[mobile-1] == false) {
            int temp = a[pos];
            a[pos] = a[pos-1];
            a[pos-1] = temp;
        } else {
            int temp = a[pos];
            a[pos] = a[pos+1];
            a[pos+1] = temp;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] > mobile)
                dir[a[i]-1] = !dir[a[i]-1];
        }

        printPermutation(a, n);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Permutations using Johnson–Trotter algorithm:\n");
    generatePermutations(n);

    return 0;
}
