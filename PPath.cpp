#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int p[5] = {1,10,100,1000,10000};

int getNumber(int node, int digit, int pos){
	int x1 = node/p[pos];
	int x2;
	if(pos == 1){
		x2 = 0;
	} else {
		x2 = node%p[pos-1];
	}
	return (x1*p[pos] + x2 + digit*p[pos-1] );
}

int main(){
	
	bool prime_flag[10000] ;
	
	for( int i =0; i<10000; i++){
			prime_flag[i] = false;
	}
	for (int i=3; i<10000; i++){
		if(i%2 == 0){
			prime_flag[i]=true;
			continue;
		}
		for(int j = 3; j <= sqrt(i); j++){
			if(i%j == 0){
				prime_flag[i] = true;
				break;
			}
		}
	}
	int T;
	cin>>T;
	while(T--){
		int S, D;
		queue < int > q;
		int cost = 0;
		bool found = false;
		cin>>S>>D;
		int visited[10000];
		for( int i =0; i<10000; i++){
			visited[i] = -1;
		}
		q.push(S);
		visited[S] = 0;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			//cout<<"node "<<node<<endl;
			if(node == D){
				found = true;
				break;
			}
			for(int j = 1; j <= 4 ; j++){
				for(int i = 0; i<=9; i++){
					if(j==4 && i == 0){
						continue;
					}
					int n = getNumber(node,i,j); 
					if((visited[n]==-1) && prime_flag[n]==false){
						visited[n] = visited[node] + 1;
						q.push(n);
					}
				}
			}
				
		}
		if(found){
			cout<<visited[D]<<endl;
		} else{
			cout<<"IMPOSSIBLE"<<endl;
		}		
		
	} 
}



