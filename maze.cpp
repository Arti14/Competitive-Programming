#include<iostream>
#include<queue>
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

min_q cell;

priority_queue < min_q, vector<min_q>, mycomparison > pq;

int main(){
        
        int flag=false;
        int maze[10][10];
        int visited[10][10];
        int m,n;
        int sp=0;
        cin>>m>>n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>maze[i][j]; 
                visited[i][j]=0;   
            }
        }
        cell.i=0;
        cell.j=0;
        cell.cost=maze[0][0];
        pq.push(cell);
        while(!pq.empty()){
            int i=pq.top().i;
            int j=pq.top().j;
            sp=pq.top().cost;
            if(i==(m-1)&&j==(n-1)){
                flag=true;
                break;
            }
            pq.pop();
            visited[i][j]=1;
            if(visited[i+1][j]==0&&(i+1)<m&&maze[i+1][j]!=-1){
                maze[i+1][j]=sp+maze[i+1][j];
                cell.i=i+1;
                cell.j=j;
                cell.cost=maze[i+1][j];
                pq.push(cell);
            }

            if(visited[i-1][j]==0&&(i-1)>=0 && maze[i-1][j]!=-1){
                maze[i-1][j]=sp+maze[i-1][j];
                cell.i=i-1;
                cell.j=j;
                cell.cost=maze[i-1][j];
                pq.push(cell);
            }

            if(visited[i][j+1]==0&&(j+1)<n && maze[i][j+1]!=-1){
                maze[i][j+1]=sp+maze[i][j+1];
                cell.i=i;
                cell.j=j+1;
                cell.cost=maze[i][j+1];
                pq.push(cell);
            }
  
            if(visited[i][j-1]==0&&(j-1)>=0 && maze[i][j-1]!=-1){
                maze[i][j-1]=sp+maze[i][j-1];
                cell.i=i;
                cell.j=j-1;
                cell.cost=maze[i][j-1];
                pq.push(cell);
            }            
                                
       }
    if(flag){
        cout<<"cost to reach "<<sp<<endl; 
    }
    else{
        cout<<"no path exists btw source to dstn "<<endl;
    }
}
  
    
    
    
