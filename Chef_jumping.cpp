#include <iostream>
using namespace std;

int main(){
	long long a;
	int ans;
	bool flag = false;
	cin>>a;
	ans = a%6;
	int jumps = 1;
	while(jumps <= 3){
		if(ans == 0){
			flag = true;
			break;
		}
		ans = ans - jumps;
		if(ans == 0){
			flag = true;
			break;
		}
		jumps++;
	}
	if(flag){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
}