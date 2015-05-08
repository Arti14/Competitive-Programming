#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N;
	int k;
	long long moves=0;
 	cin>>N>>k;
 	int x[100000];
 	int y[100000];
	for(int i=0;i<k;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<k;i++)
	{
		cin>>y[i];
	}
	int minn;
	for(int i=0;i<k;i++)
	{	
		minn=min(((x[i]-1)+(y[i]-1)),((x[i]-1)+(N-y[i])));
		minn=min(minn,((N-x[i])+(y[i]-1)));
		minn=min(minn,((N-x[i])+(N-y[i])));
		moves+=minn;
	}
	cout<<moves<<endl;
}