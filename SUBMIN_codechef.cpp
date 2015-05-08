#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int st[1000000];
vector < int > arr;

int getMid(int x, int y)
{
	return (x+y)/2;
}

int getMin(int x, int y)
{
	if(x<=y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int makeSt(int s, int e,int index)
{
	if(s==e)
	{
		st[index]=arr[s];
		return arr[s];
	}
	int mid=getMid(s,e);
	st[index]=getMin(makeSt(s,mid,2*index+1),makeSt(mid+1,e,2*index+2));
	return st[index];
}
int count;
void submin(int s, int e,int index, int q)
{
	if(s==e)
	{
		if(st[index]==q)
		{
			count=count+1;
			return;
		}
		else
		{
			return ;
		}
	}
	if(st[index]==q)
	{
		count=count+(e-s);
	}
	int mid=getMid(s,e);
	submin(s,mid,2*index+1,q);
	submin(mid+1,e,2*index+2,q);
}
int main()
{
	int N;
	int x;
	
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>x;
		arr.push_back(x);
	}
	makeSt(0,N-1,0);
	int Q;
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		int q;
		count=0;
		cin>>q;
		submin(0,N-1,0,q);
		cout<<count<<endl;
	}
}