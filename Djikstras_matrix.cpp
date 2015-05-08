#include <iostream>
#include <queue>
using namespace std;

struct min_q{
int i,j,cost;
};

class mycomparison
{
  
public:
  
  bool operator() (const min_q& lhs, const min_q& rhs) const
  {
	if (lhs.cost <= rhs.cost) {
		return false;
	}
	return true;
  }
};


priority_queue <min_q,vector<min_q>,mycomparison> pq;


int main()
{
int arr[50][50];
int visited[50][50];
int m,n;
int si,sj,di,dj;
cin>>m>>n;
cout<<endl;
for(int i=0;i<m;i++){
   for(int j=0;j<n;j++){
   cin>>arr[i][j];
   visited[i][j]=false;
   }
 }

cout<<"enter the source cell"<<endl;
cin>>si>>sj;
cout<<"enter the destination cell"<<endl;
cin>>di>>dj;
int cost=0;
min_q cell;
cell.i=si;
cell.j=sj;
cell.cost=arr[si][sj];
pq.push(cell);
while(!pq.empty())
{
	int i=pq.top().i;
	int j=pq.top().j;
	cost=pq.top().cost;
	pq.pop();
	if(i==di&&j==dj)
	{
		break;
	}

	if(visited[i+1][j]==false&&(i+1)<m)
	{
		visited[i+1][j]=true;
		arr[i+1][j]=cost+arr[i+1][j];
		cell.i=i+1;
		cell.j=j;
		cell.cost=arr[i+1][j];
		pq.push(cell);
	}

if(visited[i-1][j]==false&&(i-1)>=0){
visited[i-1][j]=true;
arr[i-1][j]=cost+arr[i-1][j];
cell.i=i-1;
cell.j=j;
cell.cost=arr[i-1][j];
pq.push(cell);
}

if(visited[i][j+1]==false&&(j+1)<n){
visited[i][j+1]=true;
arr[i][j+1]=cost+arr[i][j+1];
cell.i=i;
cell.j=j+1;
cell.cost=arr[i][j+1];
pq.push(cell);
}
  
if(visited[i][j-1]==false&&(j-1)>=0){
visited[i][j-1]=true;
arr[i][j-1]=cost+arr[i][j-1];
cell.i=i;
cell.j=j-1;
cell.cost=arr[i][j-1];
pq.push(cell);
}     

}
cout<<"cost to reach "<<cost<<endl; 
}





