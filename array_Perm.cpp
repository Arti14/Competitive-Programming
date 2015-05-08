#include <iostream>
using namespace std;
int count = 0;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void perm(int *arr, int start, int end){
	if((end-start)==1){
		//print the array before swap
		for(int i = 0; i <= end; i++){
			cout<<arr[i]<<"-";
		}
		cout<<endl;
		swap(arr[start], arr[end]);
		//print the array after swap
		for(int i = 0; i <= end; i++){
			cout<<arr[i]<<"-";
		}
		cout<<endl;
		//swap bacl to original postion
		swap(arr[start], arr[end]);
		count += 2;

	} else {
		for(int i = start; i <= end; i++){
			swap(arr[start], arr[i]);
			perm(arr, start+1, end);
			swap(arr[start], arr[i]);
		}
	}
}

int main(){
	int n;
	int arr[20];
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	perm(arr, 0, n-1);
	cout<<"no of perms: "<<count<<endl;
}