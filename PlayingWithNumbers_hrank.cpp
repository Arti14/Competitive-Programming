#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXM 500000
int pos[MAXM];
int neg[MAXM];
int preS[MAXM];
int sumP[MAXM];
int sumN[MAXM];
int find(int x, int arr[], int l, int r) {
	if(l > r) {
		return -1;
	}
	while(l+1 < r) {
		int mid = l + (r-l)/2;
		if(arr[mid] == x) {
			return mid;
		} else if(arr[mid] < x) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	//cout <<"arr[l] " << arr[l] <<" arr[r] " << arr[r] << endl;
	if(arr[l] >= x) {
		return l;
	} else if(arr[r] >= x) {
		return r;
	}
	return -1;
}
int main() {
	int N, q, x;
	int p = -1, n = -1, val;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> val;
		if(val >= 0) {
			pos[++p] = val;
		} else {
			neg[++n] = val;
		}
	}
	sort(pos, pos + p + 1);
	sort(neg, neg + n + 1);
	for(int i = 0; i <= p; i++) {
		if(i == 0) {
			sumP[i] = pos[i];
			continue;
		}
		sumP[i] = sumP[i-1] + pos[i];
	}
	for(int i = 0; i <= n; i++) {
		if(i == 0) {
			sumN[i] = abs(neg[i]);
			continue;
		}
		sumN[i] = sumN[i-1] + abs(neg[i]);
	}
	cin >> q;
	int tempX = 0;
	while(q--) {
		cin >> x;
		x += tempX;
		long long sum = 0;
		long long sum1 = 0;
		long long sum2 = 0;
		if(x >= 0) {
			if(p >= 0) sum += sumP[p] + (p+1) * x;
			int indexL = find(-x, neg, 0, n);
			//cout << " indexL "<< indexL << endl;
			if(indexL != -1) {
				sum1 = (-sumN[indexL] - neg[indexL]) + (indexL * x);
				sum2 = (-(sumN[n] - sumN[indexL]) + neg[indexL]) + (n - indexL + 1)*x;
			} else {
				if(n >= 0) sum1 = -sumN[n] + (n + 1)*x;
			}
		} else {
			if(n >= 0) sum += sumN[n] + abs((n + 1) * x);
			int indexL = find(-x, pos, 0, p); //returns index of the val equal or greater that abs(x);
			if(indexL != -1) {
				sum1 = (sumP[p] - sumP[indexL] + pos[indexL]) + (p - indexL + 1)*x; //sum of values greater than abs(x)
				sum2 = (sumP[indexL] - pos[indexL]) + indexL*x ;
			} else {
				if(p >= 0) sum1 = sumP[p] + (p + 1)*x;
			}
		}
		//cout <<"sum " << sum <<" sum1 "<< sum1 << " sum2 " << sum2 << endl;
		sum += abs(sum1) + abs(sum2);
		tempX = x;
		cout << sum << endl;
	}
	return 0;
}