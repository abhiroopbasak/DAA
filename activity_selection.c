# include <stdio.h>


int activity_selection(int s[],int e[],int a)
{
	int et=e[0],i;
	printf("\nStart time End time\n %d\t\t%d",s[0],e[0]);
	int number=1;
	for(i=0;i<a;i++)
	{
		if(s[i]>=et)
		{
			printf("\n %d\t\t%d",s[i],e[i]);
			number=number+1;
			et=e[i];
		} 	
	}
	return number;	
}


int main()
{
	int a,number,i;
	printf("Enter the number of activities: ");
	scanf("%d",&a);
	int s[a],e[a];
	printf("Enter the starting time of the activities:\n");
	for(i=0;i<a;i++)
	{
		scanf("%d",&s[i]);
	}
	printf("Enter the ending time of the activities:\n");
	for(i=0;i<a;i++)
	{
		scanf("%d",&e[i]);
	}
	number=activity_selection(s,e,a);
	printf("\nThe number of activites conducted are: %d",number);
	return 0;
}
