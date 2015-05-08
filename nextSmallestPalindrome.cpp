/* 1. if all 9's (999 -> 1001)
*/
#include <iostream>
#include <string>
using namespace std;
int arr[1000];
int n;
bool checkAll9s(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		if(arr[i] != 9) {
			return false;
		}
	}
	return true;
}

void stringToArray(string s) {
	int len = s.length();
	for(int i = 0; i < len; i++) { //0th index represents Most significant digit
		arr[i] = s[i] - '0';
	}
}
void findNextPalindrome(int n) {
	bool leftSmaller = false;
	int mid = n/2;
	int i = mid - 1;
	int j = (n % 2) == 0 ? mid : mid + 1;
	while(i >= 0 && arr[i] == arr[j]) {
		i--; j++;
	}
	if(i < 0 || arr[i] < arr[j]) {
		leftSmaller = true;
	}
	while(i >= 0) {
		arr[j] = arr[i];
		i--; j++;
	}
	if(leftSmaller) {
		int carry = 1;
		i = mid - 1;
		if(n % 2 == 1) {
			arr[mid] = arr[mid] + carry;
			carry = arr[mid] / 10;
			arr[mid] = arr[mid] % 10;
			j = mid + 1;
		} else {
			j = mid;
		}
		while (i >= 0) {
			arr[i] = arr[i] + carry;
			carry = carry / 10;
			arr[i] = arr[i] % 10;
			arr[j] = arr[i];
			i--; j++;
		}
	}
}

int main() {
	int T;
	string s;
	cin >> T;
	while(T--) {
		cin >> s;
		n = s.length();
		stringToArray(s);
		bool flag = checkAll9s(arr, n);
		if(flag) {
			arr[0] = arr[n] = 1;
			for(int i = 1; i < n; i++) {
				arr[i] = 0;
			}
			for(int i = n; i >= 0; i--) {
				cout << arr[i];
			}
			cout << endl;
			continue;
		} 
		findNextPalindrome(n);
		for(int i = 0; i < n; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}