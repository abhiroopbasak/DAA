# include <stdio.h>


void knapsack(float profit[3],float weight[3],float capacity)
{
	
	float ratio[3],tc=0,temp=0,maxprofit=0;
	for(int i=0;i<3;i++)
	{
		ratio[i]=profit[i]/weight[i];
	}
		
	float tem;
	for (int i=0;i<3;i++)
	{
		for(int j=2;j>=i;j--)
		{
			if(ratio[j]<ratio[j+1])
			{
				tem=ratio[j];
				ratio[j]=ratio[j+1];
				ratio[j+1]=tem;
				
				tem=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=tem;
				
				tem=weight[j];
				weight[j]=weight[j+1];
				weight[j+1]=tem;
			}
		}
	}
	
	
	int h=0;
	while(tc<capacity)
	{
		temp=(capacity-tc)/weight[h];
		
		if(temp<1)
		{

			if (tc==capacity)
			{
				break;
			}
			tc=tc+(temp*weight[h]);
			maxprofit=maxprofit+(temp*profit[h]);

		}
		else
		{

			if (tc==capacity)
			{
				break;
			}
			tc=tc+weight[h];
			maxprofit=maxprofit+(profit[h]);

		}
		h++;
		if(h>=3)
		{
			break;
		}
	}
	printf("Maximum Profit: %d",int(maxprofit));
}


int main()
{
	printf("Name: Abhiroop Basak \nRoll no: 13000219055 \nPCA 1 Examination\n\n");
	float profit[3],weight[3],capacity;
	printf("Enter the capacity: ");
	scanf("%f",&capacity);
	printf("Enter the profits\n");
	for(int i=0;i<3;i++)
	{
		scanf("%f",&profit[i]);
	}
	printf("Enter the weights\n");
	for(int j=0;j<3;j++)
	{
		scanf("%f",&weight[j]);
	}
	
	knapsack(profit,weight,capacity);
}
