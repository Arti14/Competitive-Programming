//front is always an index behind the element to be popped

#include <iostream>
using namespace std;
int max_size = 5;
int cqueue[5];
int front = -1;
int rear = -1;

void Push(){
	int n;
	cin>>n;
	if(rear == -1){
		cqueue[++rear] = n;// queue is empty
	}
	else if(front == -1 && rear == max_size-1){
		cout<<"Queue is full "<<endl;
		return ;
	}
	else if(rear == front){
		cout<<"Queue is full "<<endl;//in previous push rear became equal to front
		return;
	}
	else if (rear == max_size-1){
		rear =0;
		cqueue[rear] = n;
	}
	else{
		cqueue[++rear] = n;
	}

}

void Pop(){

	if(front == -1 && rear == -1 ){// queue is empty 
		cout<<"queue is empty "<<endl;
		return;
	} else {
		
		if(front == max_size-1){
			front = 0;
		} else {
			front ++;
		}
		cout<<"popped element is "<<cqueue[front]<<endl;
		if(front == rear){
			front = rear = -1;
		}
		
	}

}

void Peep(){

	if(rear >= 0){
		int fr = front+1;
		cout<<"Peeped "<<cqueue[fr]<<endl;
	} else {
		cout<<"queue is empty "<<endl;
	}
}

int main(){
bool flag = true;
	while(flag){

		int x;
		cout<<"Operations:"<<endl;
		cout<<"  1. Push"<<endl;
		cout<<"  2. Pop"<<endl;
		cout<<"  3. Peep"<<endl;
		cout<<"  4. Break"<<endl;
		cin>>x;
		switch(x){

			case 1: Push();
					break;
			case 2: Pop();
					break;
			case 3: Peep();
					break;
			case 4: flag = false;
					break;
			defualt: flag = false; 
		}
	}
}