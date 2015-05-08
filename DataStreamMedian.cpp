//maintain two heaps: min_heap and max_heap where min_heap has all elements that are greater that the effective median 
//and max_heap has all elements that are less that the effective median
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define SIZE 1000

struct heap {
	int heapsize = 0;
	int a[SIZE];
};

heap min_heap, max_heap;
void findMedian(int x, int m) {
	//find current median
	int l = min_heap.heapsize;
	int r = max_heap.heapsize;
	int median;
	if(l == r) {
		if(x >= m) {
			min_heap.insert(x);
			median = min_heap.a[0];
		} else {
			max_heap.insert(x);
			median = max_heap.a[0];
		}
	} else if(l > r) {
		if(x >= m) {
			max_heap.insert(min_heap.delete());
			min_heap.insert(x);
		} else {
			max_heap.insert(x);
		}
		median = (min_heap.a[0] + max_heap.a[0]) / 2;
	} else {
		if(x >= m) {
			min_heap.insert(x);
		} else {
			min_heap.insert(max_heap.delete());
			max_heap.insert(x);
		}
		median = (min_heap.a[0] + max_heap.a[0]) / 2;
	}
}

int main() {
	int x;
	int n, m = 0;
	cin >> n;
	while(n--) {
		cin >> x;
		m = findMedian(x, m);
		cout << m << endl;
	}
	return 0;
}