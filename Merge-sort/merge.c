#include <stdio.h>
#include <time.h>

void Merge_Sort(int a[], int low, int high);
void Merge(int a[], int low, int high, int mid);

int main() {
    int a[100000], temp[100000], i, n;
    struct timespec start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        temp[i] = a[i];
    }


    clock_gettime(CLOCK_MONOTONIC, &start);
    Merge_Sort(a, 0, n - 1);
    clock_gettime(CLOCK_MONOTONIC, &end);

    time_taken = (end.tv_sec - start.tv_sec) +
                 (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nTime taken = %.9f seconds\n", time_taken);


    printf("\n\n%-10s %-20s\n", "N", "Time (seconds)");
    printf("-----------------------------------\n");

    int step = n / 5;
    if(step == 0) step = 1;

    for(int size = step; size <= n; size += step) {

        for(i = 0; i < size; i++) {
            a[i] = temp[i];
        }

        clock_gettime(CLOCK_MONOTONIC, &start);
        Merge_Sort(a, 0, size - 1);
        clock_gettime(CLOCK_MONOTONIC, &end);

        time_taken = (end.tv_sec - start.tv_sec) +
                     (end.tv_nsec - start.tv_nsec) / 1e9;

        printf("%-10d %-20.9f\n", size, time_taken);
    }

    return 0;
}


void Merge_Sort(int a[], int low, int high) {
    int mid;
    if(low < high) {
        mid = (low + high) / 2;
        Merge_Sort(a, low, mid);
        Merge_Sort(a, mid + 1, high);
        Merge(a, low, high, mid);
    }
}

void Merge(int a[], int low, int high, int mid) {
    int c[100000];
    int i = low, j = mid + 1, k = low;

    while(i <= mid && j <= high) {
        if(a[i] <= a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    while(i <= mid) c[k++] = a[i++];
    while(j <= high) c[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = c[i];
}