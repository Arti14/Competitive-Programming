#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int primes[100000];

bool prime( int x){

	if(primes[x]==1){
		return true;
	}
	if(primes[x]== -1){
		return false;
	}
	for(int i=2; i<=sqrt(x); i++){
		if(x%i == 0){
			primes[x] = -1;
			return false;
		}
	}
	primes[x] = 1;
	return true;
}

int main(){
	int tc;
	cin>>tc;
	primes[2] = 1;//if primes[i] = 1 then it is a prime number
	primes[3] = 1;
	while(tc--){
		int n;
		cin>>n;
		string winner = "Arjit";
		if(n==2){
			cout<<winner<<endl;
			continue;
		}
		for(int i=2; i<=n; i++){
			if(prime(i)){
				if(prime(n-i)){
					winner = "Deepa";
					break;
				}
			}
		}
		cout<<winner<<endl;
	}
}
