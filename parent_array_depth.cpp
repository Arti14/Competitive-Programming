#include<iostream>
using namespace std;

int height[5];
int parent[5];
int depth(int i){
    
    if(parent[i]==-1){
        return 0;
    }
    
    if(height[i]!=-1){
        return height[i];
    }
    else{
        height[i]= depth(parent[i])+1;
    }
    return height[i];
}
int main(){
    
    for(int i=0;i<5;i++){   
        cin>>parent[i];
        height[i]=-1;
    }
    cout<<"array is  ";
    for(int i=0;i<5;i++){   
        cout<<parent[i];
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        height[i]=depth(i);
    }
    for(int i=0;i<5;i++){
        cout<<height[i]<<" ";n
    }
    cout<<endl;
}
