#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int m;
	int coin[50];
	int sum;
	int arr[10000];
	cin>>m;
	for(int i = 0; i < m; i++){
		cin>>coin[i];
	}
	cin>>sum;
	arr[0] = 1;
	for(int i = 0; i < m; i++){
		for (int j = 1; j <= sum; ++j)
		{
			if(j - coin[i] >= 0){
				arr[j] = arr[j-coin[i]] + arr[j];
			}
		}
	}
	cout<<"total no of ways "<<arr[sum]<<endl;
}