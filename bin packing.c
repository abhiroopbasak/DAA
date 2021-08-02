#include <stdio.h>


int nextfit(int s,int as,int a[10])
{
	int bin=1;
	int val=0,i;
	for (i=0;i<as;i++)
	{
		if(val+a[i]<=s)
		{
			val=val+a[i];	
		}
		else
		{
			val=0;
			bin=bin+1;
			val=val+a[i];
		}
	}
	return bin;
}

int main()
{
	int size,a_size,value,i;
	printf("Enter the size of the array: ");
	scanf("%d",&a_size);
	int a[a_size];
	printf("Enter the size of each array division: ");
	scanf("%d",&size);
	printf("Enter the inputs into array:\n");
	for(i=0;i<a_size;i++)
	{
		scanf("%d",&a[i]);
	}
	value=nextfit(size,a_size,a);
	printf("The number of bins using Nextfit Algorithm: %d",value);
	

}
