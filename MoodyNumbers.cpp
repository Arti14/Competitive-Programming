#include <iostream>
#include <cstdio>
using namespace std;
int digits[6562];
int digitSum(long long num) {
	if(num < 6562 && digits[num] != 0) {
		return digits[num];
	}
	int sum = 0;
	long long i = num;
	while(num > 0) {
		sum += num % 10;
		num = num / 10;
	}
	if(i < 6562) {
		digits[i] = sum;
	}
	return sum;
}

int main()
{
    int T;
    scanf("%d", &T);
    long long n;
    for(long long i = 1; i < 6562; i++) {
    	digits[i] = 0;
    }
    for(long long i = 1; i < 6562; i++) {
    	digits[i] = digitSum(i);
    }
    while(T--) {
    	scanf("%lld", &n);
    	if(n % 3 == 0) {
    		printf("NO\n");
    		continue;
    	}
    	if(n  == 4 || n == 1) {
    		printf("YES\n");
    		continue;
    	}
    	long long x = n;
    	bool flag = true;
    	while(x != 4 && x != 1) {
    		if(x % 3 == 0) {
    			flag = false;
    			break;
    		}
    		x = digitSum(x*x);
    		//cerr << x << " ";
    	}
    	if(!flag) {
			printf("NO\n");
    	} else {
    		printf("YES\n");
    	}
    }
    return 0;
}
