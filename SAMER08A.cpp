#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct node{
	int x;
	int cost;
};


class mycomparison
{
  
public:
  
  bool operator() (const node& lhs, const node& rhs) const
  {
	if (lhs.cost <= rhs.cost) {
		return false;
	}
	return true;
  }
};

priority_queue <node,vector<node>,mycomparison> pq;

int main()
{
	int N, M;
	cin>>N>>M;
	int s,d;
	cin>>s>>d;
	while(s!=0||d!=0)
	{
		int arr[500][500];
		vector < vector <int> > parent;

		for(int i=0;i<N;i++)
		{
			vector < int > empty;
			parent.push_back(empty); 
			for(int j=0;j<N;j++)
			{
				arr[i][j]=-1;
			}

		}
		for(int i=0;i<M;i++)
		{
			int u, v,p;
			cin>>u>>v>>p;
			arr[u][v]=p;
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		node cell;
		bool visited[500]={false};
		int count=0;
		cell.x=s;
		cell.cost=0;

		int min_cost=500001;
		pq.push(cell);
		while(!pq.empty())
		{
			int nd=pq.top().x;
			int cost=pq.top().cost;
			pq.pop();
			if(visited[nd])
			{
				continue;
			}
			if(nd==d)
			{
				if(min_cost>=cost)
				{
					count++;
					min_cost=cost;
					continue;
				}
				
				else
				{
					break;
				}
				
			}
			
			visited[nd]=true;
			for(int i=0;i<N;i++)
			{
				if(arr[nd][i]!=-1)
				{
					cell.x=i;
					cell.cost=cost+arr[nd][i];
					pq.push(cell);
					parent[i].push_back(nd);
				}
			}

		}
		cout<<parent[d].size()<<endl;
		cout<<"shortest path cost is "<<min_cost<<endl;
		cout<<"no of shortest paths "<<count<<endl;
		cin>>N>>M;
		cin>>s>>d;
	}
}