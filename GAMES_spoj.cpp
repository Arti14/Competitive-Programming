#include <iostream>
#include <string>
using namespace std;

int findgcd(long long x, int y){
	while(x!=y){
        if(x>y)
            return findgcd(x-y,y);
        else
            return findgcd(x,y-x);
    }
    return x;
}

long long atoi(string in){
	long long n = 0;
	long long multiplier = 1;
	for (int i = in.length()-1; i >= 0; --i)
	{
		if(in[i] == '.'){
			continue;
		}
		n += (int)(in[i] - '0')*multiplier;
		multiplier *= 10;	
	}
	return n;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		string in;
		cin>>in;
		int decimalPos = 0;
		for(int i = in.length()-1; i >= 0; i--){
			if(in[i] == '.'){
				break;
			}
			decimalPos++;
		}
		if(decimalPos == in.length()){
			cout<<1<<endl;
			continue;
		}
		long long num1 = atoi(in);
		int num2 = 1;
		while(decimalPos > 0){
			num2 *= 10;
			decimalPos--;
		}
		int ans = findgcd(num1, num2 );
		cout<<num2/ans<<endl;
	}
}