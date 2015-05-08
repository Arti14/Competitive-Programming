#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	int arr[100];
	int p, q;
	int diff[100];
	cin >> n;
	int maxDiff = -1;
	int M;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);	
	/*for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;*/
	cin >> p >> q;
	if(arr[0] >= q) {
		M = p;
	} else if(arr[n-1] <= p ) {
		M = q;
	} else {
		int j = 0;
		while(p > arr[j]) {
			j++;
		}
		int i;
		for(i = j+1; i < n && arr[i] <= q; i++) {
			int mid = arr[i-1] + (arr[i] - arr[i-1]) / 2;
			int diff = min(mid - arr[i-1], arr[i] - mid);
			if(diff > maxDiff) {
				maxDiff = diff;
				M = mid;
			}
		}
		//cout <<"maxDiff " << maxDiff << endl;
		i--;
		if(j > 0) {
			int mid = arr[j-1] + (arr[j] - arr[j-1]) / 2;
			int diff = min(mid - arr[j-1], arr[j] - mid);
			if(diff >= maxDiff && mid >= p) {
				maxDiff = diff;
				M = mid;
			}
		}
		if(i+1 < n) {
			int mid = arr[i] + (arr[i+1] - arr[i]) / 2;
			int diff = min(mid - arr[i], arr[i+1] - mid);
			if(diff > maxDiff && mid <= q) {
				maxDiff = diff;
				M = mid;
			}
		}
		if((arr[j] - p) >= maxDiff && j == 0) {
			M = p;
		}
		if((q - arr[i]) > maxDiff && i == n-1) {
			M = q;
		}
	}
	cout << M << endl;
}