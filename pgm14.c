#include <stdio.h>
#include <stdlib.h>
int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);
int main()
{
	printf("\n\tImplementation of Kruskal's Algorithm\n");
	printf("\nEnter the no. of vertices:");
	scanf("%d", &n);
	printf("\nEnter the cost adjacency matrix:\n");
	for (i = 1; i <= n; i++)
{
    for (j = 1; j <= n; j++)
    {
        printf("Enter cost[%d][%d]: ", i, j);
        scanf("%d", &cost[i][j]);
        if (cost[i][j] == 0)
            cost[i][j] = 999;  
    }
}

	printf("The edges of Minimum Cost Spanning Tree are\n");
	while (ne < n)
	{
	for (i = 1, min = 999; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (cost[i][j] < min)
				{
					min = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u = find(u);
		v = find(v);
		if (uni(u, v))
		{
			printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
			mincost += min;
		}
		cost[a][b] = cost[b][a] = 999;
	}
	printf("\n\tMinimum cost = %d\n", mincost);
}

int find(int i)
{
	while (parent[i])
	i = parent[i];
	return i;
}

int uni(int i, int j)
{
	if (i != j)
	{
		parent[j] = i;
		return 1;
	}
	return 0;
}

/*
/*1.Start with no edges in the MST.

2.List all edges of the graph with their weights.

3.Sort edges in increasing order of weight.

4.Pick the smallest edge from the list:

	4.1 If adding it does NOT form a cycle, include it in the MST.

	4.2 If it forms a cycle, skip it.

5.Repeat step 4 until the MST has (number of vertices - 1) edges.

6.MST complete — sum the weights of selected edges for the minimum cost.*/
