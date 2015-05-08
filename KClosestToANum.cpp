//A stream of characters is coming, at any moment you have to tell ‘k’ elements closest to a given number
/* create a max-heap of length k where each node has two fields namely key and val. Key is the abs diff of the element and given 
num and val is the actual value*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define SIZE 100
struct node {
	int key, val;
};
vector < node > heap;
int k, heapsize;

void swap(node &n1, node &n2) {
	node temp;
	temp = n1;
	n1 = n2;
	n2 = temp;
}

void maxHeapify(int index) {
	int l = 2*index + 1;
	int r = 2*index + 2;
	int largest = index;
	if(l < heapsize && heap[l].key > heap[largest].key) {
		largest = l;
	}
	if(r < heapsize && heap[r].key > heap[largest].key) {
		largest = r;
	}
	if(largest != index) {
		swap(heap[index], heap[largest]);
		maxHeapify(largest);
	}
} 

void buildMaxHeap() {
	int i = heapsize/2 - 1;
	for(; i >= 0; i--) {
		maxHeapify(i);
	}
}

void insertInHeap(node n) {
	if(heapsize < k) {
		heap[heapsize++] = n;
	} else {
		heap[0] = n;
		maxHeapify(0);
	}
}

bool insert(int val, int key) {
	//cout << val << " " << key << endl;
	node n;
	n.val = val;
	n.key = key;
	if(heapsize < k ) {
		insertInHeap(n);
		return true;
	}
	if(heapsize == k) {
		buildMaxHeap();
	}
	if(key < heap[0].key) {
		insertInHeap(n);
		return true;
	}
	return false;
}

void printKClosest() {
	for(int i = 0; i < heapsize; i++) {
		cout << heap[i].val << " " << endl;
	}
}

int main() {
	int num, c, x;
	bool flag;
	cout << "1. new element" << endl;
	cout << "2. k closest elements" << endl; 
	cin >> num >> k;
	heapsize = 0;
	for(int i = 0; i < k; i++) {
		node n ;
		heap.push_back(n);
	}
	while(true) {
		cin >> c;
		switch(c) {
			case 1: cin >> x;
					flag = insert(x, abs(x-num));
					cout << "flag: " << flag << endl;
					break;

			case 2: printKClosest();
					break;

			default : break;
		}
	}
	return 0;
}