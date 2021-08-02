#include <stdio.h>

void kruskal(int adj[3][3],int nodes)
{
	
	int node=nodes*nodes;
	int to[node],i,j;
	int from[node];
	int weight[node];
	int h=0;
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			if(adj[i][j]!=0)
			{
				to[h]=i+1;
				from[h]=j+1;
				weight[h]=adj[i][j];
				h++;
			}
		}
	}
	
	
	int temp=0;
	for(i=0;i<h;i++)
	{
		for(j=h-1;j>=0;j--)
		{
			if(weight[j]<weight[j+1])
			{
				temp=weight[j+1];
				weight[j+1]=weight[j];
				weight[j]=temp;
				
				temp=to[j+1];
				to[j+1]=to[j];
				to[j]=temp;
				
				temp=from[j+1];
				from[j+1]=from[j];
				from[j]=temp;
			}
		}
	}
	
	printf("\nPath\n");
//	for(int i=0;i<h;i++)
//	{
//		printf("%d ",weight[i]);
//	}
	printf("\n");
	for(i=0;i<h;i++)
	{
		printf("%d ",to[i]);
	}
	printf("\n");
	for(i=0;i<h;i++)
	{
		printf("%d ",from[i]);
	}
	printf("\n");
}


int main()
{
	printf("Kruskal's Algorithm\n");
//	printf("Please enter the number of nodes of the graph: ");
//	scanf("%d",&nodes);
	
	int adj[3][3],i,j;
	
	printf("Enter the adjacency matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&adj[i][j]);
			if(adj[i][j]==1)
				{
					printf("Enter the weight of the edge: ");
					scanf("%d",&adj[i][j]);
				}
		}
	}
	
	
//	for(int i=0;i<3;i++)
//	{
//		for(int j=0;j<3;j++)
//		{
//			printf("%d ",adj[i][j]);
//		}
//		printf("\n");
//	}
	kruskal(adj,3);
}
