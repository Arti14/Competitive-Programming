#include <iostream>
#include <string>
using namespace std;

int matchSub(string regex, string str){
	int i = 0;
	int j = 0;
	int val = -1;
	for(i = 0; i < str.length(); i++){
		for(j = 0; j < regex.length(); j++ ){
			if(str[i+j] != regex[j]){
				//cout<<"break"<<endl;
				break;
			}
		}
	}
	if(j == regex.length() - 1){
		val = j;
	}
	cout<<val<<endl;
	return val;

}

bool matchAstrix(string regex, string str){
	int index;
	bool fl = false;
	for(int i = 0; i < regex.length() -1; i++){
		if(regex[i] == '*'){
			index = i;
		}
	}
	string prefixregex = regex.substr(0, index-1);
	int k = matchSub(prefixregex, str);
	if(k < 0){
		return false;
	}
	int len = str.length();
	if(regex[index-1] != (k+1)){
		string prefixregex = regex.substr(index+1, regex.length());
		int k1 = matchSub(prefixregex, str);
		if(k1 < 0){
			return false;
		}else{
			return true;
		}

	}
	while(regex[index-1] == (k+1) && k < len){
		k++;
	}
	int i;
	int j;
	for(i = index+1; i < regex.length(); i++){
		for(j = k+1; j < str.length(); j++){
			if(regex[i] != str[j]){
				return fl;
			}
		}
	}
	if((i == regex.length()-1) && (j == str.length()-1)){
		return true;
	}else { 
		return false;
	}
}
bool matchDot(string regex, string str){
	int index = -1;
	bool fl = false;
	for(int i = 0; i < regex.length(); i++){
		if(regex[i] == '.'){
			index = i;
		}
	}
	if(index = -1){
		return false;
	}
	if(index > 0){
		string prefixregex = regex.substr(0, index);
		fl = matchAstrix(prefixregex, str);
		if(!fl){
			fl = matchSub(prefixregex, str);
		}
	}
	//match the latter sub string
	return fl;
}

bool matchCarot(string regex, string str){
	int i =0;
	if(regex[i] != '^'){
		return false;
	}
	i++; 
	if(regex[i] == str[i-1]){
		return true;
	} else {
		return false;
	}
}

bool matchDollar(string	regex, string str){
	int index;
	if(regex[regex.length() - 1] != '$'){
		return false;
	}
	index = regex.length() - 2;
	int last = str.length() -1;
	while(regex[index] == str[last]){
		index--;
		last--;
	} 
	//cout<<index<<endl;
	if(index == 0){
		return true;
	} else {
		return false;
	}
}


bool regexMatch(string regex, string str){

	bool fl = false;
	int index = 0;
	
	fl = matchDot(regex, str);
	cout<<fl<<endl;
	if(fl){
		return true;
	}
	fl = matchCarot(regex, str);
	if(fl){
		return true;
	}
	fl = matchDollar(regex, str);
	cout<<fl<<endl;
	if(fl){
		return true;
	}
	fl = matchAstrix(regex, str);
	if(fl){
		return true;
	}
	return fl;
	/*index = matchSub(regex, str);
	if(index > 0){
		//cout<<"here"<<endl;
		return true;
	}*/
}


int main(){
	bool flag = false;
	string regex;
	string str;
	cin>>regex;
	cin>>str;
	flag = regexMatch(regex, str);
	if(flag){
		cout<<"true"<<endl;
	} else {
		cout<<"false"<<endl;
	}
}