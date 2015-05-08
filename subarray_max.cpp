/*Segmented tree implementation*/

#include <iostream>
using namespace std;
int arr[1000000];
int st[2000000];

int getMid(int l,int r){
	return (l + r)/2;
}

int getMax(int x,int y){
 if(x>=y){
 	return x;
 }
 else{
 	return y;
 }
}
int makeST(int *arr,int ss,int se, int index){
	
	if(ss==se)
	{
		st[index]=arr[ss];
		return arr[ss];
	}
	int mid=getMid(ss,se);
	st[index]=getMax(makeST(arr,ss,mid,2*index+1),makeST(arr,mid+1,se,2*index+2));
	return st[index];
}

int max_subarr(int ss, int se,int index,int l,int r){

	if (se < l) {
		return -1;
	}
	if (ss > r) {
		return -1;
	}
	if(ss>=l && se<=r)
	{
         return st[index];
	}
	int mid=getMid(ss, se);
	return getMax(max_subarr(ss, mid, 2*index+1,l,r),max_subarr(mid+1, se, 2*index+2,l,r));
}
int main(int argc, char const *argv[])
{
	int n;
	int k, max;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>k;
	makeST(arr, 0, n-1,0);
	/*for(int i=0; i<2*n-1;i++)
	{
		cout<<i<<" "<<st[i]<<" "<<endl;
	}*/
	if(k==1){
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
	}
	if(k>1){
		for(int i=0;i<=n-k;i++){
			cout<<max_subarr(0,n-1,0,i,(i+k-1));
			if (i == n - k) {
				cout << "\n";
			} else {
				cout << " ";
			}
		}
		
	}
	
}


