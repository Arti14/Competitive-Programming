#include <iostream>
using namespace std;

int main(){
	int N, K;
	long long arr[100000];
	long long max = -2000000000;
	long long max1 = -2000000000;
	cin>>N;
	cin>>K;
	for (int i = 0; i < N; i++){
		cin>>arr[i];
		if(max<arr[i]){
			max = arr[i];
		}
	}
	cout<<endl;
	if(K==0){
		for (int i = 0; i<N; i++){
			cout<<arr[i]<<" ";
		}
	} 
	else {
		for (int i = 0; i < N; ++i)
		{
			arr[i] = max - arr[i];
			if (max1<arr[i]){
				max1 = arr[i];
			}
		}
		if (K%2==1){
			for (int i = 0; i<N; i++){
				cout<<arr[i]<<" ";
			}
		} else {
			for (int i = 0; i < N; ++i)
			{
				arr[i] = max1 - arr[i];
				cout<<arr[i]<<" ";
			}
		}
	}
	cout<<endl;
}