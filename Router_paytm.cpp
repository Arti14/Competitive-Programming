#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N[100][2];
		int M[100][2];
		int n,m;
		cin>>n>>m;
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<2;j++)
			{
				N[i][j]=0;
			}
		}
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<2;j++)
			{
				M[i][j]=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<2;j++)
			{
				cin>>N[i][j];

			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<2;j++)
			{
				cin>>M[i][j];
			}
		}
		//finding the minimum distance of user from the router
		vector < double > userR;
		for(int i=0;i<m;i++ )
		{
			double min=150;
			for(int j=0;j<n;j++)
			{
				int sum=(N[i][0]-M[j][0])*(N[i][0]-M[j][0])+(N[i][1]-M[j][1])*(N[i][1]-M[j][1]);
				double dist=sqrt(sum);
				if(min>dist)
				{
					min=dist;
				}
				userR.push_back(min);
			}
		}
		//finding the minimum distance of each router with other router
		vector < double > RR;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				double min=150;
				if(i==j)
				{
					continue;
				}
				int sum=(N[i][0]-N[j][0])*(N[i][0]-N[j][0])+(N[i][1]-N[j][1])*(N[i][1]-N[j][1]);
				double dist=sqrt(sum);
				if(min>dist)
				{
					min=dist;
				}
				RR.push_back(min);

			}
		}
		double max1=0;
		for(int i=0;i<userR.size();i++)
		{
			if(max1<userR[i])
			{
				max1=userR[i];
			}
		}
		double max2=0;
		for(int i=0;i<RR.size();i++)
		{
			if(max2<RR[i])
			{
				max2=RR[i];
			}
		}
		max1=max(max1,max2);
		cout<<max1<<endl;
	}
}