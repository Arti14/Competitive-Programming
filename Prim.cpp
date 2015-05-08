#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int vertex;
    int cost;
};

node n;

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

vector < node > edge;
vector < vector < node > > graph;
priority_queue <node, vector<node>, mycomparison> pq;

vector< bool > visited;

int mincost=0;

void min_cost(int x){
    
    n.vertex=x;
    n.cost=0;
    pq.push(n);
    while(!pq.empty()){
        x=pq.top().vertex;
        cout<<" x "<<x;
        if(!visited[x]){
            mincost=mincost+pq.top().cost;
            pq.pop();
            visited[x]=true;
            for(int i=0;i<graph[x].size();i++){
                n.vertex=graph[x][i].vertex;
                n.cost=graph[x][i].cost;
                if(!visited[n.vertex]){
                    pq.push(n);
                }
            }
        }
        else
        {
            break;
        }   
            
    }
}
    
    
    
    
int main(){
    
    n.vertex=1;
    n.cost=1;
    edge.push_back(n);
    n.vertex=2;
    n.cost=5;
    edge.push_back(n);
    graph.push_back(edge);
    edge.clear();
    n.vertex=0;
    n.cost=1;
    edge.push_back(n);
    n.vertex=3;
    n.cost=4;
    edge.push_back(n);
    graph.push_back(edge);
    edge.clear();
    n.vertex=0;
    n.cost=5;
    edge.push_back(n);
    n.vertex=3;
    n.cost=7;
    edge.push_back(n);
    n.vertex=4;
    n.cost=8;
    edge.push_back(n);
    graph.push_back(edge);
    edge.clear();
    n.vertex=2;
    n.cost=8;
    edge.push_back(n);
    n.vertex=3;
    n.cost=2;
    edge.push_back(n);
    graph.push_back(edge);
    edge.clear();
    for(int i=0;i<graph.size();i++)
    {   
        visited.push_back(false);
     }
    
    //printing graph
    for( int i=0; i<graph.size(); i++){
        for(int j=0;j<graph[i].size(); j++){
            cout<<graph[i][j].vertex<<" "<<graph[i][j].cost<<" ";
        }
        cout<<endl;
    }
    
    min_cost(0);
    cout<<" MST cost is "<<mincost<<endl;  
    
}            
    
    
    
    
