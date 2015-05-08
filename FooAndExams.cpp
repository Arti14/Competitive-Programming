#include <iostream>
using namespace std;
#define ull unsigned long long 

int a, b, c, d;
ull k;
ull calcStress(int t) {
	return (ull)a*t*t*t + (ull)b*t*t + c*t + d;
}

int binSearch(int start, int end, ull val) {
	ull temp;
	int low = start, high=end;
	while(low <= high) {
		int mid = (low+high)/2;
		temp = calcStress(mid);
		if(temp == val) {
			return mid;
		}
		if((temp < val) && (mid==end || calcStress(mid+1)  > val)){
			return mid;
		}
		if(temp > val) {
          high = mid-1;
		} else if(temp < val) {
          low = mid + 1;
		}
	} 
	
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> a >> b >> c >> d >> k;
		if(k < 8) {
			cout << "0" << endl;
			continue;
		}
		int t = binSearch(1, 1000000, k);
		//cout <<"t : " << t << endl;
		cout << t << endl;
	}
	return 0;
}