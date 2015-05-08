#include <iostream>
#include <algorithm>
# include <queue>
#include <vector>
using namespace std;

class mycomparison {
  
public:
  bool operator() (const int& lhs, const int& rhs) const {
  	if (lhs <= rhs) {
		return true;
	}
	return false;
  }
};

int main(){
	int T;
	cin>>T;
	while(T--){
		int a[1000000];
		int b[1000000];
		priority_queue <int,vector<int>,mycomparison> pq;
		int n;
		cin>>n;
		for(int i = 0; i<1000000; i++){
			b[i] = 0;
		}
		int max = 0;
		for(int i=0; i<n; i++){
			cin>>a[i];
			b[a[i]-1] += 1;
			if(b[a[i]-1]>max){
				max= b[a[i]-1];
			}
		}
		
		for(int i=0; i<1000000; i++){
			if(b[i]==max){
				pq.push(a[i+1]);
			}
		}
		while(!pq.empty()){
			cout<<pq.top()<<" ";
			pq.pop();
		}
		cout<<endl;
	}
}