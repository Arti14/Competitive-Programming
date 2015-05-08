#include <iostream>
using namespace std;

int max_size = 100;
int stack[100];
int top = -1;

void Push(){
	int n;
	cin>>n;
	if(top == -1 || top < max_size-1){
		stack[++top] = n;
	}
	else{
		cout<<"stack is full"<<endl;
	}

}

void Pop(){

	if (top == -1 ){
		cout <<"stack is empty"<<endl;
	}
	else{
		cout<<"Popped element is "<<stack[top--]<<endl;
	}
	
}

int Peep(){
	
	if (top >= 0)
	{
		return stack[top];
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