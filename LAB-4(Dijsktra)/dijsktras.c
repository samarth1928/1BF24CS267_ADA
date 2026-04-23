#include <stdio.h>
#include <conio.h>

int src, dest[10], cost[10][10], n, vis[10];

void Dijkstra()
{
    int i, j, count, min, u;

    for (i = 0; i < n; i++) {
        dest[i] = cost[src][i];
        vis[i] = 0;
    }
    dest[src] = 0;  
    vis[src] = 1;
    count = 1;

    while (count < n) {
        min = 999;
        u = -1;

        for (i = 0; i < n; i++) {
            if (vis[i] == 0 && dest[i] < min) {
                min = dest[i];
                u = i;
            }
        }

        vis[u] = 1;

        for (i = 0; i < n; i++) {
            if (vis[i] == 0 && (dest[u] + cost[u][i]) < dest[i]) {
                dest[i] = dest[u] + cost[u][i];
            }
        }
        count++;
    }
}

void main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (use 999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", n-1);
    scanf("%d", &src);

    Dijkstra();

    printf("\nShortest paths from source %d:\n", src);
    for (i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", src, i, dest[i]);
    }

    getch();
}