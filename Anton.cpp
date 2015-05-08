#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	cin >> str;
	int len = str.length();
	int index;
	bool found = false;
	int last = (int)(str[len-1] - '0');
	for(int i = len - 2; i >= 0; i--) {
		int val = (int)(str[i] - '0');
		if(val % 2 == 0) {
			if(!found) {
				index = i;
				found = true;
			} else if(last > val){
				index = i;
			}
			
		}
	}
	if(found) {
		char temp = str[index];
		str[index] = str[len-1];
		str[len-1] = temp;
		cout << str;
	} else {
		cout <<"-1";
	}
	cout << endl;
	return 0;
}