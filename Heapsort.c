#include<stdio.h>

heapify(int arr[10],int size,int i)
{
	int temp,largest,left,right;
	
	largest=i;
	left=2*i+1;
	right=2*i+2;
	
	if(arr[left]>arr[largest] && left<size)
	{
		largest=left;
	}
	if(arr[right]>arr[largest] && right<size)
	{
		largest=right;
	}
	
	if(largest!=i)
	{
		temp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		heapify(arr,size,largest);
	}
	
}

heapsort(int arr[10],int size)
{
	int temp;
	for(int i=(size/2)-1;i>=0;i--)
	{
		heapify(arr,size,i);
	}
	for (i=size-1;i>=0;i--) 
	{
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr, i, 0);
    }
}

int main()
{
	int arr[10],size;
	printf("Enter the size of the heap: ");
	scanf("%d",&size);
	printf("Enter the heap elements\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	heapsort(arr,size);
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
