#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;
string str;
stack < char > mystack;

bool isOperand(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int prec(char c) {
	switch(c) {
		case '+':
		case '-': return 1;

		case '/':
		case '*': return 2;

		case '^': return 3;
	}
	return -1;
}
void infixToPostix() {
	int k = -1;
	string ans;
	for(int i = 0; i < str.length(); i++) {
		if(isOperand(str[i])) {
			ans[++k] = str[i];
			//cout << "ans[" << k << "]" << ans[k] << endl;
		} else if (str[i] == '(') {
			mystack.push(str[i]);
		} else if(str[i] == ')'){
			while(mystack.top() != '(' && !mystack.empty()) {
				ans[++k] = mystack.top();
				//cout << "ans[" << k << "]" << ans[k] << endl;
				mystack.pop();
			}
			mystack.pop();
		} else {
			while(!mystack.empty() && prec(mystack.top()) >= prec(str[i])){
				ans[++k] = mystack.top();
				//cout << "ans[" << k << "]" << ans[k] << endl;
				mystack.pop();
			}
			mystack.push(str[i]);
		}
	}	
	while(!mystack.empty()) {
		ans[++k] = mystack.top();
		//cout << "ans[" << k << "]" << ans[k] << endl;
		mystack.pop();
	}
	//cout << ans.length() << endl;
	for(int i = 0; i <= k; i++) {
		cout << ans[i]; 
	}
	cout << endl;
}

int main() {
	cin >> str;
	infixToPostix();
	return 0;
}	