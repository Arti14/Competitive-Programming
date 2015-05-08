#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector < int > window;
vector < vector < int > > graph;
vector < bool > visited;

int main()
{
	int N, M;
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		int w;
		vector < int > vec;
		cin>>w;
		window.push_back(w);
		graph.push_back(vec);
		visited.push_back(false);

	}
	int x,y;
	long sum=0;
	long pair=0;
	for(int i=0;i<M;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i=0;i<graph.size();i++)
	{
		if(visited[i])
		{
			continue;
		}
		queue < int > q;
		q.push(i);
		long count=0;

		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			if(visited[x])
			{
				continue;
			}
			if(window[x]==1)
			{
				count++;
			}
			visited[x]=true;
			for(int k=0;k<graph[x].size();k++)
			{
				q.push(graph[x][k]);
			}

		}
		if(count>1)
		{
			sum=sum+count;
			pair=pair+count*(count-1)/2;
		}
	}
	cout<<pair<<" "<<sum<<endl;

}