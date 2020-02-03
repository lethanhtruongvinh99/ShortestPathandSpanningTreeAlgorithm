#define V 10000
#include "GRAPH.h"
int CREATE(int u, int v, int w, int** adjList)
{
	--u;
	--v;
	if (adjList[u][v] != 0 && adjList[v][u] != 0)
		return 0;
	else
	{
		adjList[u][v] = w;

		adjList[v][u] = w;

		return 1;
	}
}

int DELETE(int u, int v, int** adjList)
{
	--u;
	--v;
	if (adjList[u][v] == 0 && adjList[v][u] == 0)
		return 0;
	else
	{
		adjList[u][v] = 0;

		adjList[v][u] = 0;

		return 1;
	}
}

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < MAX_N; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

int dijkstra(int** graph, int src, int end,int* trace)
{
	int dist[V];

	bool sptSet[V];

	for (int i = 0; i < V; i++)
	{
		trace[i] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)
				if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				{
					trace[v] = u;
					dist[v] = dist[u] + graph[u][v];
				}
	}
	/*int id = end;
	cout << "x";
	do
	{
		cout << id+1 << ' ';
		id = trace[id];
	} while (id != -1);
	cout << endl;*/
	if (dist[end] == INT_MAX)
		return -1;
	return dist[end];
}
