#include <iostream>
using namespace std;

int max_size = 100;
int queue[100];
int front = -1;
int rear = -1;

void Push(){
	int n;
	cin>>n;
	if(front == -1 ){
		front ++;
		queue[++rear] = n;
	}
	else if(rear < max_size-1){
		queue[++rear] = n;
	}
	else{
		cout<<"queue is full"<<endl;
	}

}

void Pop(){

	if (front == -1 ){
		cout <<"queue is empty"<<endl;
	}
	else{
		cout<<"Popped element "<<queue[front++]<<endl;
	}
	
}

int Peep(){
	
	if (front >= 0)
	{
		return queue[front];
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
			case 3: cout<<"peeped "<<Peep()<<endl;
					break;
			case 4: flag = false;
					break;
			defualt: flag = false; 
		}
	}

}