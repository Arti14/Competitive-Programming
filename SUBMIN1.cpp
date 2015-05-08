#include <iostream>
#include <cmath>
using namespace std;

int arr[50];

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	int Q;
	int count;
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		int q;
		cin>>q;
		int count=0;

		for(int i=0;i<N;i++)
		{
			int T=arr[i];
			for(int j=i;j<N;j++)
			{
				T=min(arr[j],T);
				if(T==q)
				{
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
}