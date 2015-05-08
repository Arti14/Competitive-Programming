#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int index=0;
	while(n!=0)
	{
		int arr[1000][1000];
		int B=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&arr[i][j]);
				B+=arr[i][j];

			}

		}
		int A[1000]={0};
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]!=0)
				{
					A[i]=A[i]+arr[i][j];
					A[j]=A[j]-arr[i][j];
				}
				
			}

		}
		int reduce=0;
		for(int i=0;i<n;i++)
		{
			if(A[i]>0)
			{
				reduce+=A[i];
			}
		}
		cout<<++index<<". "<<B<<" "<<reduce<<endl;
		cin>>n;

	}
}












