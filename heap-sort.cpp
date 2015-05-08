#include <iostream>
using namespace std;
int arr[1000000];
int heapsize;

void maxHeapify(int index) {
	int l = 2 * index + 1;
	int r = 2 * index + 2; 
	int largest = index;
	if(l < heapsize) {
		if(arr[l] > arr[largest]) {
			largest = l;
		}
	}
	if(r < heapsize) {
		if(arr[r] > arr[largest]) {
			largest = r;
		}
	}
	if(largest != index) {
		int temp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = temp;
		maxHeapify(largest);
	}
}
void buildMaxHeap(int n) {
	heapsize = n;
	for(int i = n/2 - 1; i >= 0; i--) {
		maxHeapify(i);
	}
}

void heapsort(int n) {
	while(heapsize > 1) {
		int temp = arr[heapsize-1];
		arr[heapsize-1] = arr[0];
		arr[0] = temp;
		heapsize--;
		maxHeapify(0);
	}
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	buildMaxHeap(n);
	heapsort(n);
	for(int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}