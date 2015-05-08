/* 
	sortedIndex[k][i] has the sorted-position of ith suffix when pow(2, k) characters are taken into account
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAXLG 17
#define MAXB 65536

struct entry{
	int nr[2];
	int p;
}L[MAXLG];

int sortedIndex[MAXLG][MAXB]; 

int cmp(entry a, entry b) {
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}
int main() {
	string s;
	int step;
	int count;
	cin >> s;
	int N = s.length();
	for(int i = 0; i < N; i++) {
		sortedIndex[0][i] = s[i] - 'a';
	}
	for(step = 1, count = 1; count < N; step++, count = count*2) {
		for(int i = 0; i < N; i++) {
			L[i].nr[0] = sortedIndex[step-1][i];
			L[i].nr[1] = i+count < N ? sortedIndex[step-1][i+count] : -1;
			L[i].p = i;
		}
		sort(L, L+N, cmp);
		for(int i = 0; i < N; i++) {
			sortedIndex[step][L[i].p] = i>0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1] ? sortedIndex[step][L[i-1].p] : i; 
			// if ith tuple is same as (i-1)th tuple then the pos of L[i-1].p and L[i].p will be same in sortedIndex Array
		}
	}
	for(int i = 0; i < N; i++) {
		cout << sortedIndex[step-1][i] << endl;
	}
	return 0;
}