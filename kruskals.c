#include <stdio.h>
int parent[20];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
int main()
{
    int n, e;
    int u[20], v[20], w[20];
    int i, j, temp;
    int count = 0, cost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
     for (i = 0; i < e - 1; i++)
    {
        for (j = i + 1; j < e; j++)
        {
            if (w[i] > w[j])
            {
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
                temp = u[i];
                u[i] = u[j];
                u[j] = temp;
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < e && count < n - 1; i++)
    {
        if (find(u[i]) != find(v[i]))
        {
            printf("%d - %d : %d\n", u[i], v[i], w[i]);
            cost += w[i];
            unionSet(u[i], v[i]);
            count++;
        }
    }
    printf("Minimum Cost = %d\n", cost);
    return 0;
}