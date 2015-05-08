#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		int tmp=m;
		if(m==n)
		{
			cout<<1<<"/"<<1<<endl;
			continue;
		}
		for(int i=2;i<=sqrt(m);i++)
		{
			if(tmp%i==0)
			{
				if(n%i==0)
				{
					tmp=tmp/i;
					n=n/i;
				}
				else
				{
					continue;
				}
			}
		}
		cout<<m<<"/"<<n<<endl;
	}
}