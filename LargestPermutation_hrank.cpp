#include <iostream>
#include <map>
using namespace std;
int arr[100005];
int index[100005];
void swap(int l, int r) {
	int temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
}

int main() {
	int n, k;
	bool flag = true;
	cin >> n >> k;
	index[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		index[arr[i]] = i;
	}
	int count = 0;
	int curr = n;
	for(int i = 1; i < n  && count < k; i++) {
		if(curr != arr[i]) {
			int tmp = index[curr];
			index[curr] = index[arr[i]];
			index[arr[i]] = tmp;
			swap(i, tmp);
			count++;
		}
		curr--;
	}

	for(int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	
	cout << endl;
	return 0;
}