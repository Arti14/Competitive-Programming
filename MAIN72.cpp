#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int N;
		int arr[100];
		int maxSum = 0;
		bool sumArr[100001];
		int x;
		int sum = 0;
		cin>>N;
		for(int i = 0; i < N; i++){
			cin>>arr[i];
			maxSum += arr[i];
		}
		sumArr[0] = true;
		for(int i = 1; i <= maxSum; i++){
			sumArr[i] = false;
		}
		int tempSum = 0;
		for(int i = 0; i < N; i++){
			tempSum += arr[i];
			sumArr[tempSum] = true;
			for(int j = tempSum-1; j > 0; --j){
				if(sumArr[j] == true){
					continue;
				}
				if((j-arr[i]) >= 0 && sumArr[j-arr[i]] == true){
					sumArr[j] = true;
				}
			}
		}
		for(int i = 1; i <= maxSum; i++){
			if(sumArr[i]){
				sum += i;
			}
		}
		cout<<sum<<endl;
	}
}