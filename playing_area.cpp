#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	long long n;
	while(T--)
	{
		cin>>n;
		long long L,B;
		L=n/4;
		B=n/2-L;
		long long ans;
		ans=L*B;
		cout<<ans<<endl;
	}
}