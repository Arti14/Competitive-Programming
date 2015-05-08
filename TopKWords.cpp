#include <iostream>
#include <fstream>
#include <string>
using namespace std;

# define MAX_CHARS 26
struct TrieNode {
	bool isWord;
	int frequency;
	int indexMinHeap;
	TrieNode* edges[MAX_CHARS];
};
TrieNode* root = NULL;

struct MinHeapNode {
	TrieNode *tPointer;
	int frequency;
	string word;
};

struct MinHeap {
	int capacity;
	int heapsize;
	MinHeapNode *array;
};

TrieNode* newTrieNode() {
	TrieNode* t = new TrieNode;
	t->isWord = false;
	t->frequency = 0;
	t->indexMinHeap = -1;
	for(int i = 0; i < MAX_CHARS; i++) {
		t->edges[i] = NULL;
	}
	return t;
}

MinHeap* createMinHeap(int capacity) {
	MinHeap *minHeap = new MinHeap;
	minHeap->capacity = capacity;
	minHeap->heapsize = 0;
	minHeap->array = new MinHeapNode[capacity];
	return minHeap;
}

void swapHeapNodes(MinHeapNode* a, MinHeapNode* b) {
	MinHeapNode temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(MinHeap* minHeap, int index) {
	int l = 2*index + 1;
	int r = 2*index + 2; 
	int smallest = index;
	int heapsize = minHeap->heapsize;
	if(l < heapsize && minHeap->array[l].frequency < minHeap->array[smallest].frequency) {
		smallest = l;
	}
	if(r < heapsize && minHeap->array[r].frequency < minHeap->array[smallest].frequency) {
		smallest = r;
	}
	if(smallest != index) {
		minHeap->array[smallest].tPointer->indexMinHeap = index;
		minHeap->array[index].tPointer->indexMinHeap = smallest;
		swapHeapNodes(&minHeap->array[smallest], &minHeap->array[index]);
		minHeapify(minHeap, smallest);
	}
}
void buildMinHeap(MinHeap* minHeap) {
	int n = minHeap->heapsize - 1;
	for(int i = n/2; i >= 0; i--) {
		minHeapify(minHeap, i);
	}
}

void insertInMinHeap(TrieNode **node, string word, MinHeap* minHeap) {

	int index = (*node)->indexMinHeap;
	if((*node)->indexMinHeap != -1) { //word already exists in minHeap
		minHeap->array[index].frequency++;
		if(minHeap->heapsize >= minHeap->capacity) {
			minHeapify(minHeap, index);
		}
	} else if(minHeap->heapsize < minHeap->capacity) {
		int heapsize = minHeap->heapsize;
		minHeap->array[heapsize].frequency = 1;
		minHeap->array[heapsize].word = word;
		minHeap->array[heapsize].tPointer = *node;
		(*node)->indexMinHeap = heapsize;
		minHeap->heapsize++;
	} else {
		if(minHeap->heapsize == minHeap->capacity) {
			buildMinHeap(minHeap);
		}
		if((*node)->frequency > minHeap->array[0].frequency) {
			TrieNode* n = minHeap->array[0].tPointer;
			minHeap->array[0].tPointer = *node;
			(*node)->indexMinHeap = 0;
			n->indexMinHeap = -1;
			minHeap->array[0].word = word;
			minHeap->array[0].frequency = (*node)->frequency;
			minHeapify(minHeap, 0);
		}
	}
}

void insert(TrieNode* node, string word, int pos, MinHeap* minHeap) {
	if(pos == word.length()) {
		if(node->isWord) {
			(node->frequency)++;

		} else {
			node->isWord = true;
			node->frequency = 1;
		}
		insertInMinHeap(&node, word, minHeap);
		return;
	}
	int index = tolower(word[pos]) - 'a';
	TrieNode* n = node->edges[index];
	if(n == NULL) {
		n = newTrieNode();
		node->edges[index] = n;
	}
	insert(n, word, pos+1, minHeap);
}

void displayMinHeap( MinHeap* minHeap )
{
    int i;
    for( i = 0; i < minHeap->heapsize; ++i ) {
        cout << minHeap->array[i].word << " " << minHeap->array[i].frequency << endl;
    }
}
void insertTrieAndHeap(string word, MinHeap* minHeap) {
	insert(root, word, 0, minHeap);
}

int main() {
	int k;
	string output;
	cin >> k;
	MinHeap* minHeap = createMinHeap(k);
	root = new TrieNode;
	ifstream myfile;
	myfile.open("file.txt");	
	if(myfile.is_open()) {
		while(!myfile.eof()) {
			myfile >> output;
			//cout << output << " " << endl;
			insertTrieAndHeap(output, minHeap);
		}
		myfile.close();
	}
	displayMinHeap(minHeap);
	cout << endl;
	return 0;
}