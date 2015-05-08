//find smallest K elements in an unsorted array
#include <iostream>
using namespace std;
int heapsize;
int arr[100];

void swap(int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void maxHeapify(int index) {//bottom up heapify
	int l = (2*index) + 1;
	int r = (2*index) + 2;
	cout << "index l r " << index << " " << l << " " << r << endl;
	int largest = index;
	if(l < heapsize && arr[largest] < arr[l]) {
		largest = l;
	}
	if(r < heapsize && arr[largest] < arr[r]) {
		largest = r;
	}
	if(index != largest) {
		swap(index, largest);
		maxHeapify(largest);
	}
}

void buildMaxHeapFirstK(int k) {
	int l = (k-1)/2;
	for(int i = l; i >= 0; i--) {
		maxHeapify(i);
	}
}

void insertInMaxHeap(int index) {
	if(arr[0] > arr[index]) {
		arr[0] = arr[index];
		maxHeapify(0);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	heapsize = k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	buildMaxHeapFirstK(k);
	for(int i = k; i < n; i++) {
		insertInMaxHeap(i);
	}
	cout << "k smallest elements are :"<< endl;
	for(int i = 0; i < k; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}