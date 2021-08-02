#include<stdio.h>


void merge(int arr[], int l, int m, int r)
{
    int i, j;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    int k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
     while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) 
	{
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[10], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
 

int main()
{
	int count,arr[10];
	int i;
	printf("Number of elements:");
	scanf("%d",&count);
	for (i =0;i<count;i++)
	{
		scanf("%d",&arr[i]);
	}
    mergeSort(arr, 0, count - 1);
    printf("\nSorted array\n");
    printArray(arr, count);
    return 0;
}
