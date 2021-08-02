#include <stdio.h>


int kmp(char original[],char search[],int n,int m)
{
	int loc,flag=21,i,j;
	for(i=0;i<n-m;i++)
	{
		if (original[i]==search[0])
		{
			flag=i;
			for(j=1;j<m;j++)
			{
				if(search[j]==original[i+j])
				{
					return flag;
				}
				else
				{
					flag=i+j;
					break;
				}
			}
		}
	}
	return -1;
}


int main()
{
	char original[20];
	char search[5];
	int n,m,loc;
	printf("Enter the original string size: ");
	scanf("%d",&n);
	printf("Enter the search string size: ");
	scanf("%d",&m);
	
	printf("Enter the original string:\n");
	scanf("%s",&original);
	printf("Enter the search string:\n");
	scanf("%s",&search);
	

	loc=kmp(original,search,n,m);
	
	printf("The string is between %d and %d",loc,loc+m);
	return 0;
}
