#include <stdio.h>
#define INF 999
int main()
{
    int n;
    int graph[20][20];
    int selected[20] = {0};
    int i, j;
    int edges = 0;
    int min, x, y;
    int cost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }
    selected[0] = 1;
    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n - 1)
    {
        min = INF;
        for (i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, min);
        cost += min;
        selected[y] = 1;
        edges++;
    }
    printf("Minimum Cost = %d\n", cost);
    return 0;
}