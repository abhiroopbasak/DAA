# include <stdio.h>


void sort(int hold[],int value[],int z)
{
	int tem;
	for (int i=0;i<z;i++)
	{
		for(int j=z-1;j>=i;j--)
		{
			if (j+1 !=4)
			{
				if(value[j]<value[j+1])
				{
					tem=value[j];
					value[j]=value[j+1];
					value[j+1]=tem;
				
					tem=hold[j];
					hold[j]=hold[j+1];
					hold[j+1]=tem;
				}
			}
			
		}
	}
	
	
	for (int i=0;i<z;i++)
	{
		for(int j=z-1;j>=i;j--)
		{
			if (value[i]==value[j])
			{
				if(hold[i]>hold[j])
					{
						tem=value[j];
						value[j]=value[i];
						value[i]=tem;
				
						tem=hold[j];
						hold[j]=hold[i];
						hold[i]=tem;
					}
			
			
			}
		}
	}

	for (int i=0;i<z;i++)
	{
		printf("%d ",hold[i]);
	}
	printf("\n");
}




void new_sort(int arr[],int n)
{
	int new_array[n];
	int hold[n];
	int value[n];
	int z=0;
	
	for(int i=0;i<n;i++)
	{
		hold[i]=-1;
	}
	
	for(int i=0;i<n;i++)
	{
		int count=1;
		int flag=0;
		
		for(int k=0;k<n;k++)
		{
			if(arr[i]==hold[k])
			{
				flag=1;
				break;
			}
		}
		
		if(flag==0)
		{
			for(int j=i+1;j<n;j++)
			{
				if(arr[j]==arr[i])
				{
					count+=1;
				}
			}
			hold[z]=arr[i];
			value[z]=count;
			z++;	
		}
		
	}
	
	sort(hold,value,z);
	
}


int main()
{
	printf("Name: Abhiroop Basak \nRoll no: 13000219055 \nPCA 1 Examination\n\n");
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[j]);
		}
		new_sort(arr,n);
		
	}
	return 0;
}
