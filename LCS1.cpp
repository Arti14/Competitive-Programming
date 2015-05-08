#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	string s1;
	string s2;
	int n, m;
	cin>>m>>n;
	cin>>s1>>s2;
	int res[100][100];
	int max_sub = 0;
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i==0 || j==0){
				res[i][j] = 0;
			} else {
				if(s1[i-1] == s2[j-1]){
					res[i][j] = res[i-1][j-1] + 1;
				} else {
					res[i][j] = 0;
				}
				if(max_sub < res[i][j]){
					max_sub = res[i][j];
				}
			}
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"max "<<max_sub<<endl;
}