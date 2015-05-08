#include <iostream>
#include <cmath>
using namespace std;

int arr[100][2];
int dp[501][101];
int Budget;

int knapsack(int budget, int nP)
{
	

	if(dp[budget][nP]!=0)
	{
		return dp[budget][nP];
	}

	if (nP==1){
        if (arr[nP-1][0]<=budget){
            dp[budget][nP] = arr[nP-1][1];
            return arr[nP-1][1];
        }
        else{
            dp[budget][nP] = 0;
            return 0;
        }
    }
	if(arr[nP-1][0]<=budget)
	{
		
			dp[budget][nP]=max(arr[nP-1][1]+knapsack(budget-arr[nP-1][0],nP-1), knapsack(budget,nP-1));	
	}
	else
	{
			dp[budget][nP]= knapsack(budget,nP-1);
	}
	
	
	
	return dp[budget][nP];
			
}

int main()
{
	int nP;
	cin>>Budget>>nP;
	while(Budget!=0&&nP!=0)
	{
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<2;j++)
				{
					arr[i][j]=0;
				}
		}
		for(int i=0;i<nP;i++)
		{
			for(int j=0;j<2;j++)
			{
				cin>>arr[i][j];
			}

		}
		for(int i=0;i<500;i++)
		{
			for(int j=0;j<100;j++)
				{
					dp[i][j]=0;
				}
		}
		int max=0;
		int maxm=0;
		int minBudget=0;
		for(int i=0;i<=Budget;i++)
		{
			max=knapsack(i, nP);
			if(maxm<max)
			{
				maxm=max;
				minBudget=i;
			}
		}
		
		cout<<minBudget<<" "<<maxm<<endl;
		cin>>Budget>>nP;
	}
}
