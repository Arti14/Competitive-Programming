#include<iostream>
#include<vector>
using namespace std;

vector < int > agnes;
vector < vector < int > > tom;
vector < int > route;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n1;
		cin>>n1;
		while(n1!=0)
		{
			agnes.push_back(n1);
			cin>>n1;
		}
		int i,j;
		for(i=0;i<1000;i++)
		{
			for(j=0;j<1000;j++)
			{
				cin>>n1;
				route.push_back(n1);
				if(n1==0)
				{
					break;
				}
			}
			if(route[0]==0)
			{
				break;
			}
			tom.push_back(route);
			route.clear();
		}
		for(i=0;i<tom.size();i++)
		{
			for(j=0;j<tom[i].size();j++)
			{
				cout<<tom[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}