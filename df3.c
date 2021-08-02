#include<stdio.h>

void dfs(int);
int a[20][20],s[20],visited[20],n,i,j,f=0,t=-1;

int main()
{
	int v;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
    {
		s[i]=0;
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
	dfs(v);

    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
           printf("\nDFS is not possible. Not all nodes are reachable");
           break;
        }
    }
//	getch();
	return 0;
}

void dfs(int v)
{
    printf("%d->",v);
    //to set visited for first node
    visited[v]=1;
	for (i=1;i<=n;i++)
    {
	  if(a[v][i] && !visited[i])
      {
	   s[++t]=i;
	   visited[s[t]]=1;
      }
    }

	if(t!=-1)
    {
		dfs(s[t--]);
	}
}
