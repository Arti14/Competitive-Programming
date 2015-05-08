#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int superior[100000];
string arr[100000];
int childFound[100000];
int findReviews(int x, int y, int count){
	
	if(superior[x] == y){
		return count;
	}
	else if(superior[x]==0 && (y-1)!=x){
		return -1;
	}
	else{
		count = count+1;
		return findReviews(superior[x]-1,y, count);
	}
}

int create(int i) {
	if (superior[i] == 0) {
		arr[i] = "0";
		childFound[i]++;
		return arr[i] + (char)("0" + childFound[i]);
	}
	if (arr[i] == "") {
		arr[i] = create(superior[i]);
	}
	childFound[i]++;
	return arr[i] + (char)("0" + childFound[i]);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int q;
		int x, y;
		scanf("%d",&n);
		int sup = 0;
		for(int i=0;i<n;i++){
			scanf("%d", &superior[i]);
			if (superior[i] == 0) {
				sup = i;
			}
			arr[i] = "";
			childFound[i] = 0;
		}

		for (int i = 0; i < n; ++i) {
			create(i);
		}
		scanf("%d", &q);
		while(q--){
			scanf("%d %d", &x,&y);
			int reviews = findReviews(x-1, y, 0);
			cout<<reviews<<endl;
		}

	}
}