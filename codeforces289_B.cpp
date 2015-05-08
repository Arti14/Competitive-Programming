#include <iostream>
using namespace std;
int main() {
	int n, k;
	int arr[100];
	int peb[100][100];
	bool flag = true;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			peb[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++) {
		int equalPeb = arr[i] / k;
		for(int j = 0; j < k; j++) {
			peb[i][j] = equalPeb;
		}
		int remaining = arr[i] % k;
		for(int j = 0; j < remaining; j++) {
			peb[i][j]++;
		}
	}
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < n; j++) {
			for(int l = j+1; l < n; l++) {
				if((peb[i][j] - peb[i][l]) > 1 || (peb[i][j] - peb[i][l]) < -1) {
					flag = false;
					break;
				}
			}
			if(!flag) {
				break;
			}
			
		}
		if(!flag){
			break;
		}
		
	}
	if(!flag) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < arr[i]; j++) {
				cout << (j % k) + 1 << " ";
			}
			cout << endl;
		}
	} 
	return 0;
} 