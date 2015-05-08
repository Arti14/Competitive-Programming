#include <iostream>
using namespace std;

int main()
{
	int T;
	int n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		if(n>5)
		{
			cout<<0<<endl;
			continue;
		}
		int fact=1;
		while(n>0)
		{
			fact=fact*n;
			n--;
		}
		int d_fact=1;
		while(fact>0)
		{
			d_fact=d_fact*fact;
			fact--;
		}
		cout<<d_fact<<endl;
	}

}