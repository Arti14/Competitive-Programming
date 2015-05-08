#include <iostream>
#include <string>
using namespace std;
void swap(char &a, char &b) {
	char c = a;
	a = b;
	b = c;
}

void stringPermute(int i, string str, int len) {
	if(i == len - 1) {
		cout << str << " ";
		return;
	}
	for(int j = i; j < len; j++) {
		swap(str[i], str[j]);
		//cout << "swap " << i <<" " << j <<" "<< str << endl;
		stringPermute(i+1, str, len);
		swap(str[i], str[j]);
	}
}
int main() {
	string str;
	cin >> str;
	int len = str.length();
	stringPermute(0, str, len);
	cout << endl;
	return 0;
}