#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAXSIZE 100010
#define MOD 1000000007

int arr[MAXSIZE];
bool primesFlag[330];
bool visited[MAXSIZE];
int factors[MAXSIZE];
vector < int > primes;

long long fast_exp(int base, int exp) {
    long long res=1;
    while(exp > 0) {
       if(exp %2 == 1) res = (res*base)%MOD;
       base = (base*base)%MOD;
       exp /= 2;
    }
    return res % MOD;
}

int main() {
	int T;
	int n;
	cin >> T;
	primesFlag[1] = false;
	for(int i = 2; i < 330; i++) {
		primesFlag[i] = true;
	}
	for(int i = 2; i < 330; i++) {
		if(!primesFlag[i]) {
			continue;
		}
		primes.push_back(i);
		for(int j = i*2; j < 330; j += i) {
			primesFlag[j] = false;
		}
	}
	while(T--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
			visited[i] = false;
			factors[i+1] = 0;
		}
		long long ans = 1;
		long long count;
		for(int j = 0; j < n; j++) {
			count = 0;
			if(visited[j]) {
				continue;
			}
			visited[j] = true;
			int index = j+1;
			int nextpos = arr[j];
			count++;
			while(index != nextpos) {
				visited[nextpos-1] = true;
				nextpos = arr[nextpos-1];
				count++;
			}
			int x = count;
			for(int k = 0; k < primes.size() && primes[k]*primes[k] <= count; k++) {
				int power = 0;
				while(x > 1 && x % primes[k] == 0) {
					power++;
					x = x/primes[k];
				}
				factors[primes[k]] = max(factors[primes[k]], power);
				if(x <= 1) {
					break;
				}
			}
			if(x > 1) {
				factors[x] = max(factors[x], 1);
			}
		}
		for(int i = 2; i <= n; i++) {
			if(factors[i] >= 1) {
				//cout << i << " " << factors[i] << endl;
				ans = (ans * fast_exp(i, factors[i])) % MOD;
			}
		}
		cout << ans  << endl;
	}
	return 0;
}