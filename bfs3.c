#include<stdio.h>
void bfs(int);
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;

int main()
{
	int v;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
    {
		q[i]=0;
		visited[i]=0;
	}
	printf("\n Enter graph data in matrix form:\n");
	for (i=1;i<=n;i++)
    {
	  for (j=1;j<=n;j++)
      {
       printf("a[%d][%d]=",i,j);
	   scanf("%d",&a[i][j]);
      }
    }
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	printf("\nThe order of traversal is:");
	bfs(v);
	/*for (i=1;i<=n;i++)
    {
      if(i==v)
        printf("\n%d\tis starting node",i);
	  else if(visited[i])
      {
	    printf("\n%d\tis reachable",i);
      }
      else
        printf("\n%d\tis not reachable",i);
    }*/

    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
           printf("\nBFS is not possible. Not all nodes are reachable");
           break;
        }
    }

//	getch();
	return 0;
}

void bfs(int v)
{
    printf("%d ",v);
    //to set visited for first node;
    visited[v]=1;
	for (i=1;i<=n;i++)
    {
	  if(a[v][i] && !visited[i])
      {
	   q[++r]=i;
	   visited[q[r]]=1;
      }
    }

	if(f<=r)
		bfs(q[f++]);
}
