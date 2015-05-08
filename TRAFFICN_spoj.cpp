#include <iostream>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;



struct node
{
	int x;
	int cost;
};


struct node1
{
	int x,y;
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
	int q;
	cin>>q;
	int n,m,k,s,t;
	while(q--)
	{
		int sps_n[10000]={-1};
		int spd_n[10000]={-1};
		vector < vector < node > > oneway;
		vector < vector < node > > r_oneway;
		vector < node1 > twoway;

		scanf("%d %d %d %d %d",&n,&m,&k, &s, &t);
		for(int i=0;i<n;i++)
		{
			vector < node > empty;
			oneway.push_back(empty);
			vector < node > empty1;
			r_oneway.push_back(empty1);
		}
		for(int i=0;i<m;i++)
		{
			node inner;
			int di, ci, li;
			scanf("%d %d %d",&di,&ci,&li);
			inner.x=ci-1;
			inner.cost=li;
			oneway[di-1].push_back(inner);
			inner.x=di-1;
			r_oneway[ci-1].push_back(inner);
		}
		for(int j=0;j<k;j++)
		{
			node1 inner1;
			int uj, vj, qj;
			scanf("%d %d %d",&uj,&vj,&qj);
			inner1.x=uj-1;
			inner1.y=vj-1;
			inner1.cost=qj;
			twoway.push_back(inner1);
		}
			int source=s-1;
		
			bool visited[10000]={false};
			long min_cost=0;
			node inner;
			inner.x=source;
			inner.cost=0;
			pq.push(inner);
			while(!pq.empty())
			{
				int nd=pq.top().x;
				min_cost=min_cost+pq.top().cost;
				pq.pop();
				if(visited[nd])
				{
					continue;
				}
				visited[nd]=true;
				sps_n[nd]=min_cost;
				
				for(int j=0;j<oneway[nd].size();j++)
				{
					if(!visited[oneway[nd][j].x])
					{
						inner.x=oneway[nd][j].x;
						inner.cost=oneway[nd][j].cost;

						pq.push(inner);
					}
				}

			}
			
			
			int dest=t-1;
			for(int j=0;j<n;j++)
				{
					visited[j]=false;
				}
			min_cost=0;
			inner.x=dest;
			inner.cost=0;
			pq.push(inner);
			while(!pq.empty())
			{
				int nd=pq.top().x;
				min_cost=min_cost+pq.top().cost;
				pq.pop();
				if(visited[nd])
				{
					continue;
				}
				visited[nd]=true;
				spd_n[nd]=min_cost;
				
				for(int j=0;j<r_oneway[nd].size();j++)
				{
					if(!visited[r_oneway[nd][j].x])
					{
						inner.x=r_oneway[nd][j].x;
						inner.cost=r_oneway[nd][j].cost;

						pq.push(inner);
					}
				}

			}
			
		int ans=10000001;
		for(int i=0;i<twoway.size();i++)
		{ 	
			int x=twoway[i].x;
			int y=twoway[i].y;
			if(sps_n[x]!=-1&&spd_n[y]!=-1)
			{
				ans=min(ans,sps_n[x]+twoway[i].cost+spd_n[y]);
			}
			if(sps_n[y]!=-1&&spd_n[x]!=-1)
			{
				ans=min(ans,sps_n[y]+twoway[i].cost+spd_n[x]);
			}
		}
		if(sps_n[t-1]!=-1)
		{
			ans=min(ans,sps_n[t-1]);
		}
		if(ans==10000001)
		{
			ans=-1;
		}
		cout<<ans<<endl;
		
	}
}


