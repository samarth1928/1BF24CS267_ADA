#include <stdio.h>

#define MAX 20
#define INF 999

int find(int parent[], int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int parent[], int u, int v) {
    int a = find(parent, u);
    int b = find(parent, v);
    parent[a] = b;
}

int main() {
    int n, i, j;
    int cost[MAX][MAX];
    int parent[MAX];
    int totalCost = 0, edges = 0;
    int min, u = 0, v = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    while(edges < n - 1) {
        min = INF;

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if(find(parent, u) != find(parent, v)) {
            printf("%d - %d : %d\n", u, v, min);
            totalCost += min;
            unionSet(parent, u, v);
            edges++;
        }

        cost[u][v] = cost[v][u] = INF;
    }

    printf("Total Cost = %d\n", totalCost);

    return 0;
}
