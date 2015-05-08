#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	int n, x,y;
	cin>>T;
	while(T--)
	{
		vector < int > intial;
		vector <int > final;
		long long effort=0;
		cin>>n>>x>>y;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			intial.push_back(a);
			final.push_back(b);
		}
		sort(intial.begin(),intial.end());
		sort(final.begin(), final.end());
		for(int i=0;i<n;i++)
		{
			if(intial[i]<final[i])//putting up
			{
				effort+=x*(final[i]-intial[i]);
			}
			if(intial[i]>final[i])
			{
				effort+=y*(intial[i]-final[i]);
			}
		}
		cout<<effort<<endl;
	}
}