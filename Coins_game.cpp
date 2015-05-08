#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int T;
    int index=0;
    cin>>T;
    while(T--){
        long long N,C,K;
        int p=0;
        cin>>N>>K>>C;
        if(K%N==0){
            p=C;
            cout<<"1 ";
          }
        else if(K/N<1){
            p=N%K+C;
            cout<<"2 ";
        }
        else{
            p=N-K/sqrt(K)+C;
            cout<<"3 ";
        }
        cout<<"Case #"<<++index<<": "<<p<<endl;
     }
    cout<<endl;
}
            
      
            
