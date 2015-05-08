#include <iostream>
#include <string>
using namespace std;

int charToInt(char c) {
	return (int)(c - '0');
}
int main() {
	int T;
	string s;
	cin >> T;
	while(T--) {
		cin >> s;
		int arr[101];
		int carry = 0;
		int len = s.length();
		for(int i = 0; i < len; i++) {
			arr[i] = 0;
			arr[i] = charToInt(s[len - i - 1]);
		}
		carry = 1;
		for (int i = 0; i < len; ++i) {
			arr[i] += carry;
			carry = arr[i] / 10;
			arr[i] = arr[i] % 10;
		}

		if (carry) {
			arr[len++] = carry;
		}

		int i = len - 1;
		while (i >= 0 && (arr[i] == 3 || arr[i] == 5)) {
			--i;
		}

		if (i >= 0) {
			int j = i;
			if (arr[j] < 3) {
				arr[j] = 3;
			} else if (arr[j] < 5) {
				arr[j] = 5;
			} else {
				arr[j] = 3;
				carry = 1;
				//cout << "here!\n";
				for (int k = j + 1; k < len; ++k) {
					if (arr[k] == 5) {
						arr[k] = 3;
						carry = 1;
					} else {
						arr[k] = 5;
						carry = 0;
						break;
					}
				}
				if (carry == 1) {
					arr[len++] = 3;
				}
			}

		}
		--i;
		while (i >= 0) {
			arr[i--] = 3;
		}

		for(int k = len - 1; k >= 0; k--) {
			cout << arr[k];
		}
		cout << endl;
	}
	return 0;
}