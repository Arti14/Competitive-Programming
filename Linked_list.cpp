#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

node *head = NULL;

void insertNode(int x){

	node *n1 = new node;
	n1->data = x;
	n1->next = NULL;
	if(head == NULL){
		head = n1;
		return;
	}
	n1->next = head;
	head = n1; 
	node *newnode = head;
	while(newnode!=NULL){
		cout<<newnode->data<<" ";
		newnode = newnode->next;
	}
}

void deleteNode( int x){

	node *tmp , *tmp1;
	tmp = head; //node to be deleted
	tmp1 = head; // previous node 
	while(tmp!=NULL){
		
		if(tmp->data == x){
			if(head->data == x){
				head = tmp->next;
				tmp->next = NULL;
				delete tmp;
			}
			else{
				tmp1->next = tmp->next;
				tmp->next = NULL;
				delete tmp;
			}
		}
		tmp1 = tmp;
		tmp = tmp->next;
	}
	if(tmp==NULL){
		cout<<"node not found "<<endl;
	}
}

bool searchNode(int x){
	node *tmp = head;
	while(tmp!=NULL){
		if(tmp->data == x){
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

int main(){

	bool flag = true;
	cout<<"Operations:"<<endl;
	cout<<"  1. Insertion"<<endl;
	cout<<"  2. Deletion"<<endl;
	cout<<"  3. Search"<<endl;
	cout<<"  4. Break"<<endl;
	while(flag){

		int x;
		int n;
		cout<<"enter options 1-4"<<endl;
		cin>>x;
		switch(x){

			case 1: cout<<"enter the node for insertion "<<endl;
					cin>>n;
					insertNode(n);
					break;
			case 2: cout<<"enter the node for Deletion"<<endl;
					cin>>n;
					deleteNode(n);
					break;
			case 3: cout<<"enter the node to be searched"<<endl;
					cin>>n;
					if(searchNode(n)){
						cout<<"node found "<<endl;
					} else {
						cout<<" node not found "<<endl;
					}
					break;
			case 4: flag = false;
					break;
			defualt: flag = false; 
		}
	}
}
