#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,m,p;
	cin>>n>>m>>p;
	map <int , vector<int> > modify;
	for (int i = 0; i < n; i++){
		vector <int> list;
		modify[i] = list;
	}
	for (int i = 0; i < p; i++){
		int x, y;
		cin>>x>>y;
		modify[x-1].push_back(y-1);
	}
	for ( int i = 0; i < n; i++){
		if(modify[i].size()>1){
			sort(modify[i].begin(), modify[i].end());
		}
		
	}
	for (int i = 0; i < modify.size(); i++){
		if(modify[i].size()==0){
				cout<<m-1<<endl;
				continue;
		}
		int arr[100000];
		int cost = 0;
		for (int j = 0; j < modify[i].size(); j++){
			arr[modify[i][j]] += 1;	
		}
		for (int k = m-1; k > 0; k--)
		{
			if ((arr[k]+k+1) < (arr[k-1]+k)){
				cost = -1;
				break;
			} else {
				cost += arr[k] + 1 - arr[k-1];
			}

		}
		cout<<cost<<endl;
	}

}