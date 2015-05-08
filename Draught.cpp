#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector < int > window;
vector < vector < int > > graph;
vector < bool > visited;

long count;

long dfs( int node, long pair)
{
	
	if(visited[node])
	{
		return 0 ;
	}
	visited[node]=true;
	for(int i=0; i< graph[node].size();i++)
	{
		pair=pair+dfs(graph[node][i],pair);
		if(window[node]==1)
		{
			count++;
			pair=pair+1;
		}
		else if(pair>0)
		{
			pair=pair+1;
		}
		return pair;
		
	}
	
}
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
	long rooms=0;
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
		if(visited[i]||window[i]!=1)
		{
			continue;
		}
		count=0;
		long room=dfs(i,0);
		cout<<"count "<<count<<" room "<<room<<endl;
		if(count>1)
		{
			sum=sum+count;
			rooms=rooms+room*(room-1)/2;
		}
		cout<<" rooms "<<rooms<<" sum "<<sum<<endl;
	}
	cout<<rooms<<" "<<sum<<endl;

}