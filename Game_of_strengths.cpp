#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long modulo = 1000000007;
long long abs(long long a, long long b){
	if(a>=b){
		return (a-b) % modulo;
	} else {
		return (b-a) % modulo;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--){
		long long arr[100000];
		long long n;
		long long sum = 0;
		long long max =0;

		cin>>n;
		for(int i=0; i<n; i++){
			scanf("%lld", &arr[i]);
			if(max<arr[i]){
				max = arr[i];
			}
			sum = (sum + arr[i]) % modulo;
		}
		sort(arr, arr + n);

		long long total_sum = 0;
		for( int i=0; i<n; i++){
			total_sum = (total_sum + ((sum - (((n - i) * arr[i]) % modulo)) % modulo)) % modulo;
			sum = (sum - arr[i]) % modulo;
		}

		long long power;
		power = (max * total_sum)%modulo;

		if (power < 0) {
			power += modulo;
		}
		cout<<power<<endl;
	  }
	  return 0;
	}