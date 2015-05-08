#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		int a[100000];
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int notone=0;
		int two=0;
		long long count=0;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]>2)
			{
				count=count+notone+two;
				notone++;
			}
			if(a[i]==2)
			{
				count=count+notone;
				two++;
			}
		}
		cout<<count<<endl;

	}
}