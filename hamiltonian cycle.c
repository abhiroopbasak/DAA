#include<stdio.h>
#include<stdbool.h>
#define V 5

void printSolution(int path[]);

bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
	int i;
	if (graph [ path[pos-1] ][ v ] == 0)
		return false;

	for (i = 0; i < pos; i++)
		if (path[i] == v)
			return false;

	return true;
}


bool hamilton_check(bool graph[V][V], int path[], int pos)
{
	int v;
	if (pos == V)
	{
		if ( graph[ path[pos-1] ][ path[0] ] == 1 )
		return true;
		else
		return false;
	}

	for (v = 1; v < V; v++)
	{
		if (isSafe(v, graph, path, pos))
		{
			path[pos] = v;

			if (hamilton_check (graph, path, pos+1) == true)
				return true;
			path[pos] = -1;
		}
	}

	return false;
}


bool hamilton(bool graph[V][V])
{
	int *path = new int[V];
	for (int i = 0; i < V; i++)
		path[i] = -1;
	path[0] = 0;
	if ( hamilton_check(graph, path, 1) == false )
	{
		printf("\nSolution does not exist");
		return false;
	}

	printSolution(path);
	return true;
}


void printSolution(int path[])
{
	printf ("Solution Exists:"
			" Following is one Hamiltonian Cycle \n");
	for (int i = 0; i < V; i++)
		printf(" %d ", path[i]);


	printf(" %d ", path[0]);
	printf("\n");
}

int main()
{
	printf("Enter the adj matrix for the graph\n");
	bool graph[V][V];
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	hamilton(graph);



	return 0;
}

