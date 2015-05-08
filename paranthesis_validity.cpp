#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	string str;
	bool flag = true;
	cin>>str;
	stack <char> mystack;
	for(int i = 0; i <str.length(); i++){
		if(str[i] == '{' || str[i] == '(' || str[i] == '['){
			mystack.push(str[i]);
		} else {
			if(mystack.empty()){
				flag = false;
				break;
			}
			char topchar = mystack.top();
			if(topchar == '{'){
				if(str[i] == '}'){
					mystack.pop();
					continue;
				} else {
					flag = false;
					break;
				}
			}
			if(topchar == '('){
				if(str[i] == ')'){
					mystack.pop();
					continue;
				} else {
					flag = false;
					break;
				}
			}
			if(topchar == '['){
				if(str[i] == ']'){
					mystack.pop();
					continue;
				} else {
					flag = false;
					break;
				}
			}
		}
	}
	if(!mystack.empty()){
		flag = false;
	}
	if(flag){
		cout<<"valid string "<<endl;
	} else {
		cout<<"invalid string "<<endl;
	}
}