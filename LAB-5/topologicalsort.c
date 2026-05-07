#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int order[MAX];
    int count = 0;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                order[count++] = i;
                indegree[i] = -1;
                found = 1;

                for (int j = 0; j < n; j++) {
                    if (adj[i][j] == 1)
                        indegree[j]--;
                }
                break;
            }
        }

        if (!found) {
            printf("Graph has a cycle. Topological ordering not possible.\n");
            return;
        }
    }

    printf("Topological Ordering of vertices: ");
    for (int i = 0; i < n; i++)
        printf("%d ", order[i]);
    printf("\n");
}

int main() {
    int n;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the digraph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(n, adj);

    return 0;
}
