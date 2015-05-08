#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		string str;
		int open = 0;
		int close = 0;
		int ans = 0;
		cin>>str;
		if(str[0]=='>'){
			cout<<0<<endl;
			continue;
		}
		int len = str.length();
		int start = 0;
		int length = 0;
		while(start < len){
			if(str[start]=='<'){
				open++;
				length++;
			}
			if(str[start]=='>'){
				close++;
				length--;
			}
			if(length == 0){
				ans = 2*close;
			}
			if(close > open){
				break;
			}
			start++;
		}
		cout<<ans<<endl;
	}
}