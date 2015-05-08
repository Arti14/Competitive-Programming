#include <iostream>
#include <map>
using namespace std;

#define MAXSIZE 3
struct Node {
	int val;
	Node* next;
	Node* prev;
};
Node *front, *rear;
map <int, Node*> hashMap;

Node* deletKeyFromHashMap() {
	int key = rear->val;
	hashMap.erase(key);
}

void deleteLastNodeFromTheQueue() {
	Node* temp = rear;
	rear = rear->prev;
	temp->next = NULL;
	temp->prev = NULL;
	delete temp;
}

Node* addNodeInQueue(int x) {
	//check if queue is already full 
	if(hashMap.size() == MAXSIZE) {
		deletKeyFromHashMap(); //delete key and return the node address 
		deleteLastNodeFromTheQueue();
	}
	Node *newNode = new Node;
	newNode->val = x;
	newNode->next = front;
	newNode->prev = NULL;
	if(rear == NULL) {
		rear = newNode;
	}
	Node *temp = front;
	if(temp != NULL) {
		temp->prev = newNode;
	}
	front = newNode; //update front to point to the new node
	return newNode;
}

void addKeyInHashMap(Node *n, int key) {
	hashMap[key] = n;
}

void updateNodeInQueue(Node *n) {
	//if there if only one node in the queue then no need to update
	if(front == rear && front != NULL) {
		return;
	}
	//if node to be updated is already in front then no need to update
	if(front == n) {
		return;
	}
	//if node to updated is the last node then move the rear pointer to its previous node
	if(rear == n) {
		rear = rear->prev;
		//rear->next = NULL:
	}
	n->prev->next = n->next;
	n->next->prev = n->prev;
	n->next = NULL;
	n->prev = NULL;
	delete n;
}

bool search(int x) {
	if(hashMap.count(x) > 0) {
		Node *n = hashMap[x];
		updateNodeInQueue(n); //if frame is present in the cache, bring it in the front of the queue
		return true;;
	}

	Node *n = addNodeInQueue(x);//if frame is not present, add it in the queue
	addKeyInHashMap(n, x); //update the hashMap
	return false;
}

int main() {
	int x;
	bool flag;
	front = rear = NULL;
	while(1) {// Add nodes in the DLL and Map
		cin >> x;
		if(x < 0) {
			break;
		}
		flag = search(x);
		if(flag) {
			cout <<"found!";
		} else {
			cout <<"not found!";
		}
		cout << endl;
	}
	return 0;
}