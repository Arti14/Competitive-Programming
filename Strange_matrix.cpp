#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n,m,p;
	long long arr[100000];
	int modify[100000][2];
	cin>>n>>m>>p;
	for (int k = 0; k < p; k++){
		int i , j;
		scanf("%d %d", &i, &j);
		modify[k][0] = i;
		modify[k][1] = j;
	}
	

	for (int i = 0; i < n; i++ ){
		
		for(int j = 0; j < m; j++){
			arr[j] = j+1;
		}
		
		for (int k = 0; k < p; k++){
			if (modify[k][0] == (i+1)){
				arr[modify[k][1]-1]++;
			}
		}
		long long cost = 0;
		for (int j = m-1; j > 0; j--){
			if (arr[j] >= arr[j-1]){
				cost += arr[j] - arr[j-1];
			}
			else {
				cost = -1;
				break;
			}
		}
		cout<<cost<<endl;
	}
}