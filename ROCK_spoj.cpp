#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int dp[205][205];
int rock(char stick[],int l, int r)
{
	if(l+1==r)
	{
		if(stick[l]=='1')
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
	if (dp[l][r]!=-1)
	{
		return dp[l][r];
	}
	
	int yes=0;
	int no=0;
	int k;
	for(k=l;k<r;k++)
	{
		if(stick[k]=='1')yes++;
		else no++;	
	}
	if(yes>no)
	{
		dp[l][r]=yes+no;
		return dp[l][r];
	}
	for(k=l+1;k<r;k++)
	{
		dp[l][r]=max(dp[l][r],rock(stick,l,k)+rock(stick,k,r));
	}
	return dp[l][r];

}
int main()
{
	int T;
	
	scanf("%d", &T);
	while(T--)
	{
		int n;
		char stick[300];
		scanf("%d %s", &n, stick);
		for (int i = 0; i <= n; ++i)
		{
			for(int j=0;j <=n;j++)
			{
				dp[i][j]=-1;
			}
		}
		
		int length=rock(stick,0,n);
		cout<<length<<endl;
	}
}