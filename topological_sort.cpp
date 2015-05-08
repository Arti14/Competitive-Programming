#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector < vector < int > > graph;
stack < int > topoStack;

bool flag = true;

void topo_DFS( int node, bool visited[] )
{
	visited[node]=true;
	for(int i= 0 ; i<graph[node].size(); i++)
	{
		
		if(!visited[graph[node][i]])
		{
			
			topo_DFS(graph[node][i],visited);
		}
	}
	topoStack.push(node);
}

int main()
{
	int V, E;// no. of vertices and edges
	while(1)
	{
		cin>>V>>E;
		if(V==0 || E==0)
		{
			break;
		}
		for(int i=0;i<V;i++)
		{
			vector < int > edge;
			graph.push_back(edge);
		}
		for(int i=0;i<E;i++)
		{
			int u , v;// edge from u to v
			cin>>u>>v;
			graph[u].push_back(v);
		}
		bool visited[100];
		bool temp_visited[100];
		for(int i=0;i<V;i++)
		{
			visited[i]=false;
		}

		for(int i=0;i<V;i++)
		{
			if(!visited[i])
			{
				topo_DFS(i, visited);
			}
		}

		if(!flag)
		{
			cout<<"not a DAG "<<endl;
			continue;
		}
		while(!topoStack.empty())
		{
			cout<<topoStack.top()<<" ";
			topoStack.pop();
		}
		
	}

}