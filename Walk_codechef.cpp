#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		int w[1000000];
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>w[i];
		}
		int count=0;
		int maxm=0;
		int ans;
		for(int i=0;i<N;i++)
		{
			
			if(maxm<=w[i])
			{
				maxm=w[i];
				count=i;
			}
			
		}
		ans=maxm+count;
		for(int i=count+1;i<N;i++)
		{
			
			maxm--;
			if(maxm < w[i])
			{
				ans += (w[i]-maxm);
				maxm = w[i];
			}
		}
		cout<<ans<<endl;
	}
}