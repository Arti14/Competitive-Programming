#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int arr[10000];
	int arr1[10000];
	int n;
	int max = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	for(int i = 0; i < n; i++){
		arr1[i] = 1;
		for(int j = i-1; j >= 0; j--){
			if(arr[j] < arr[i]){
				if(arr1[i] < arr1[j]+1){
					arr1[i] = arr1[j]+1;
				}
			}
		}
		cout<<arr1[i]<<" ";
		if(max < arr1[i]){
			max = arr1[i];
		}
	}
	cout<<max<<endl;

}