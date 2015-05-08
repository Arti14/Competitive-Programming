#include <iostream>
#include <vector>
using namespace std;

vector < int > superior;
int height[100];

int findHeight(int soldier){
	if(superior[soldier] == soldier){
		return 0;
	}
	if(height[soldier]!=0){
		return height[soldier];
	}
	height[soldier] = findHeight(superior[soldier])+1;
	return height[soldier];
}


int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		height[i]=0;
		superior.push_back(x);
	}
	for (int i=0; i<n; i++){
		height[i] = findHeight(i);
	}
	for(int i = 0; i < n; i++){
		cout<<"soldier "<<i<<"height "<<height[i]<<endl;
	}
}