#include <iostream>
using namespace std;

void zeroSumSubset(int arr[], int subset[], int pos, int index, int sum, int n) {
	if(n == pos) {
		return;
	}

	if(sum == 0 && index > 0) {
		for(int i = 0; i < index; i++) {
			cout << i << " " << subset[i] << endl;
		}
		return;
	}
	subset[index] = arr[pos];
	zeroSumSubset(arr, subset, pos+1, index+1, sum + arr[pos], n);
	zeroSumSubset(arr, subset, pos+1, index, sum, n);
}
int main() {
	int arr[100];
	int subset[100];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] *= -1;
	}
	zeroSumSubset(arr, subset, 0, 0, 0, n);
}