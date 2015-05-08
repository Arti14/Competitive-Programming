#include <iostream>
using namespace std;

int arr1[100];
int arr2[100];
int res;
void findKth(int l1, int h1, int l2, int h2, int k){
	int m1 = (l1+h1)/2;
	int m2 = (l2+h2)/2;
	if((h1==(l1+1)) && (h2==(l2+1))){
		if(arr1[l1] < arr2[l2]){
			if(k == (l1+l2-1)+2){
				res = arr1[l1];
			}
			else if(k == (l1+l2)+2){
				if(arr1[h1] < arr2[l2]){
					res = arr1[h1];
				}
				else{
					res = arr2[l2];
				}
			}
			else if(k==(l1+l2+1)+2){
				if(arr1[h1] > arr2[l2]){
					res = arr1[h1];
				}
				else{
					res = arr2[l2];
				}
			}
			else{
				if(arr1[h1] > arr2[h2]){
					res = arr1[h1];
				}
				else{
					res = arr2[h2];
				}
			}
		} else {
			if(k == (l1+l2-1)+2){
				res = arr1[l2];
			}
			else if(k == (l1+l2)+2){
				if(arr1[h2] < arr2[l1]){
					res = arr1[h2];
				}
				else{
					res = arr2[l1];
				}
			}
			else if(k==(l1+l2+1)+2){
				if(arr1[h2] > arr2[l1]){
					res = arr1[h2];
				}
				else{
					res = arr2[l1];
				}
			}
			else{
				if(arr1[h1] > arr2[h2]){
					res = arr1[h1];
				}
				else{
					res = arr2[h2];
				}
			}

		}


		return;
	}
	if(arr1[m1] > arr2[m2]){
		if ((m1+m2)+2 > k){
			h1 = m1;
		}
		else if ((m1+m2)+2 < k){
			l2 = m2;
		} 
		else {
			h1 = m1;
			l2 = m2;
		}
		findKth(l1, h1, l2, h2, k);

	}
	if(arr2[m2] > arr1[m1]){
		if ((m1+m2)+2 > k){
			h2 = m2;
		}
		else if ((m1+m2)+2 < k){
			l1 = m1;
		} 
		else {
			l1 = m1;
			h2 = m2;
		}
		findKth(l1, h1, l2, h2, k);

	}
}
int main(){
	int n1, n2;
	int m1, m2, l1, l2, h1, h2;
	int k;
	cin>>n1>>n2;
	for(int i = 0; i < n1; i++){
		cin>>arr1[i];
	}
	for(int i = 0; i < n2; i++){
		cin>>arr2[i];
	}
	cin>>k;
	findKth(0, n1-1, 0, n2-1, k);
	cout<<res<<endl;
}