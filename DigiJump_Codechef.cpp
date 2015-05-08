#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
struct Node{
	int index;
	int cost;
};

class mycomparison {
  
public:
  bool operator() (const Node& lhs, const Node& rhs) const {
  	if (lhs.cost <= rhs.cost) {
		return false;
	}
	return true;
  }
};

priority_queue <Node,vector<Node>,mycomparison>  pq;

int main(){
	string in;
	cin>>in;
	int length = in.length();
	bool visited[100000];
	map <char , vector<int> > mymap;
	map <char, vector<int> > :: iterator it;
	for(int i = 0; i < length; i++ ){
		visited[i] = false;
	}
	for(int i = 0; i < length; i++ ){
		mymap[in[i]].push_back(i);
	}
	for(int i = 0; i<mymap.size(); i++){
		for (int j = 0; j < mymap[i].size(); ++j)
		{
			cout<<mymap[i][j]<<" ";
		}
		cout<<endl;
	}
	//push the first element in the queue
	Node n ;
	n.index = 0;
	n.cost = 0;
	pq.push(n);
	while(!pq.empty()){
		n = pq.top();
		pq.pop();
		visited[n.index] = true;
		if(n.index == length-1){
			break;
		}
		Node n1 ;
		//push previous element
		if(!visited[n.index - 1] && n.index > 0){
			n1.index = n.index - 1;
			n1.cost = n.cost + 1;
			pq.push(n1);
		}
		//push same elements
		if(mymap[in[n.index]].size() > 1){
			//cout<<"ele "<<in[n.index]<<endl;
			for(int i = 0; i < mymap[in[n.index]].size(); i++){
				if(mymap[in[n.index]][i] > n.index){
					//cout<<mymap[in[n.index]][i]<<endl;
					n1.index = mymap[in[n.index]][i];
					n1.cost = n.cost + 1;
					pq.push(n1);
				}
			}
		}
	}
	cout<<n.cost<<endl;

}