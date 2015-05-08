/*In simple words, a number is said to be a Smith Number if its digit_sum is equal to the sum of digit_sums_of_all_its_prime_factors.
For each range L to R (both inclusive), output the number of Smith Numbers in this range.*/
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

#define MAXINT 10000000

vector < int > primes;
bool isPrime[MAXINT+1];
bool isSmithNumberArray[MAXINT+1];
int CF[MAXINT+1];
int factorSum[MAXINT + 1];
int prefactor[MAXINT + 1];


int digitSum(int num) {
	int sum = 0;
	while(num > 0) {
		sum += num % 10;
		num = num / 10;
	}
	return sum;
}

void findPrime() {
	int maxRoot = sqrt(MAXINT) + 1;
	for (int i = 0; i <= MAXINT; ++i) {
		prefactor[i] = 0;
		isPrime[i] = (i % 2);
		if (i % 2 == 0) {
			prefactor[i] = 2;
		}
		isSmithNumberArray[i] = false;
	}

	for(int i = 3; i <= maxRoot ; i += 2) {
		if(!isPrime[i]) {
			continue;
		}
		for(int j = i * i; j <= MAXINT; j += 2 * i) {
			isPrime[j] = false;
			prefactor[j] = i;
		}
	}
	
	factorSum[0] = factorSum[1] = 0;
	factorSum[2] = 2;
	for (int i = 2; i <= MAXINT; i++) {
		if (prefactor[i] == 0) {
			isSmithNumberArray[i] = true;
			factorSum[i] = digitSum(i);
		} else {
			factorSum[i] = factorSum[i / prefactor[i]] + factorSum[prefactor[i]];
			if (digitSum(i) == factorSum[i]) {
				isSmithNumberArray[i] = true;
			}
		}
	}
}

/**
void findSmithNumbers() {
	for (int i = 2; i <= MAXINT; ++i) {
		isSmithNumberArray[i] = false;
		remainingNum[i] = i;
		factorSum[i] = 0;
	}

	for (int i = 0; i < primes.size(); ++i) {
		int sumDigit = digitSum(primes[i]);
		for (int j = primes[i]; j <= MAXINT; j += primes[i]) {
			while (remainingNum[j] % primes[i] == 0) {
				remainingNum[j] /= primes[i];
				factorSum[j] += sumDigit;
			}
		}
	}

	for (int i = 2; i <= MAXINT; ++i) {
		if (remainingNum[i] > 1) {
			factorSum[i] += digitSum(remainingNum[i]);
		}
		if (factorSum[i] == digitSum(i)) {
			isSmithNumberArray[i] = true;
		}
	}
	//cout << endl;
}
*/
int main() {
	findPrime();
	//cerr << "1";
	//findSmithNumbers();
	//cerr << "2";
	CF[1] = 0;
	for(int i = 2; i <= MAXINT; i++) {
		CF[i] = CF[i-1];
		if(isSmithNumberArray[i]) {
			CF[i] += 1;
		}
	}
	int T;
	int L, R, ans;
	//ios_base::sync_with_stdio(false);
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &L, &R);
		ans = CF[R] - CF[L-1];
		printf("%d\n", ans);
	}
	return 0;
}	