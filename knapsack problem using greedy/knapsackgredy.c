#include<stdio.h>
#include<math.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
	float x[20], c;
	float total_profit = 0;
	int i,j;

	c=capacity;
	for(i=0; i<n; i++)
		x[i]=0.0;

	for(i=0; i<n; i++)
	{
		if(weight[i] > c)
			break;
		else
		{
			x[i]=1.0;
			total_profit = total_profit + profit[i];
			c = c - weight[i];
		}
	}

	if(i < n)
		x[i]=c/weight[i];

	total_profit = total_profit+(x[i]*profit[i]);

	printf("\n The Selected elements are : \n");
	for(i=0; i<n; i++)
			printf("\n%f Part of Profit %f with weight %f", x[i], profit[i], weight[i]);

	printf("\n\n Total maximum profit for %d objects with capacity %f = %f\n", n, capacity, total_profit);

}

int main()
{
	float weight[20], value[20],ratio[20],  temp;
	float capacity;
	int n, i, j;

	printf("\n knapsack problem using Greedy Algorithm");
	printf("\n\n Enter number of objects : \t ");
	scanf("%d", &n);

	printf("\nEnter the capacity of knapsack: ");
	scanf("%f", &capacity);

	for(i=0; i < n; i++)
	{
		printf("Enter %d(th)  weight : \t ", (i+1));
		scanf("%f", &weight[i]);
		printf("Enter %d(th)  value or profit : \t ", (i+1));
		scanf("%f", &value[i]);
		ratio[i]=value[i]/weight[i];
	}

	printf("\n  Object \t");
	for(i=0; i < n; i++)
		printf("%d \t", (i+1));

	printf("\n   Weight \t");
	for(i=0; i < n; i++)
		printf("%d  \t", (i+1), weight[i]);

	printf("\n   Value \t");
	for(i=0; i < n; i++)
		printf("%d  \t", value[i]);

	printf("\nv/w ratio \t");
	for(i=0; i < n; i++)
		printf("%.2f  \t", ratio[i]);

	for(i=0; i < n; i++)
		for(j=i+1; j < n; j++)
		{
			if(ratio[i] < ratio[j])
			{
				temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;

				temp = weight[j];
				weight[j] = weight[i];
				weight[i] = temp;

				temp = value[j];
				value[j] = value[i];
				value[i] = temp;

			}
		}

	knapsack(n, weight, value, capacity);

	printf("\n The total time including the sort complexity is O(nlogn) : %f \t" , n*(log(n)/log(2)));
	printf("\n\n");
	return 0;
}
