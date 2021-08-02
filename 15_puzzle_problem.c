#include<stdio.h>


int count(int I[4][4])
{
	int zero,total=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for (int k=0;k<4;k++)
			{
				for (int l=0;l<4;l++)
				{
					if (i<k and j<l)
					{
						
					}
					else
					{
						if (I[k][l]<I[i][j])
						{
							if (I[k][l]!=0 or I[i][j]!=0)
								total=toal+1
						}
					}
				}
			}
			if (I[i][j]==0)
			{
				zero=i;
			}
		}
	}
	return total+zero;
	
}


int possible(int I[4][4],int G[4][4])
{
	int x=count(I);
	int y=count(G);
	if (x%2==0 && y%2==0)
	{
		return 1;
	}
	else if (x%2 ==1 && y%2==1)
	{
		return 1;
	}
	return 0;
}


int main()
{
	int I[4][4],G[4][4];
	
	
	printf("Enter the initial matrix");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			scanf("%d",&I[i][j]);
		}
	}
	
	printf("Enter the goal matrix");
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
	
	if possible(I,G)==1:
		print("\nSuch a move is possible!\n");
	else:
		print("\nSuch a move is not possible!\n")
}
