#include<stdio.h>

void prims();

int cost[10][10], vis[10], VT[10], ET[10][10], e=0, i, j, k, u, v, sum=0, n, m;

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix:\n");

    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            scanf("%d", &cost[i][j]);
        }
    }

    for (i=1; i<=n; i++){
        vis[i] = 0;
    }

    prims();

    printf("Minimum Spanning Tree:");
    for (i=1; i<=e; i++){
        printf("\n%d -> %d", ET[i][1], ET[i][2]);
    }

    printf("\nTotal cost = %d", sum);

    return 0;
}

void prims(){
    int x=1, min;

    VT[x]=1;
    vis[x]=1;

    for (i=1; i<=n-1; i++){  
        j = x;
        min = 999;

        while (j>0){
            k = VT[j];

            for (m=1; m<=n; m++){  
                if (cost[k][m] != 0 && cost[k][m] < min && vis[m]==0){
                    min = cost[k][m];
                    u = k;
                    v = m;
                }
            }
            j--;
        }

        VT[++x] = v;
        ET[i][1] = u;
        ET[i][2] = v;
        e++;                      
        vis[v] = 1;
        sum = sum + cost[u][v];
    }
}