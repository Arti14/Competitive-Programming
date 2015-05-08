#include<iostream>
#include<string>
using namespace std;

int main(){
    int T, N;
    int index = 1;
    string yes = "YES", no = "NO";
    string sq[20];
    cin>>T;
    while(T--){
    cout << "Case #" << index++ << ": ";
    cin>>N;
    int total=0;
    for(int i=0;i<N;i++){
        cin>>sq[i];
        for(int j=0;j<N;j++){
            if(sq[i][j]=='#'){
                total++;
            }
        }
    }
    if(total==1){
        cout << yes << "\n";
        continue;
    }
    int count=0;
    int i,j;
    for(i=0;i<N;i++){
        j=0;
        while(j<N){
            if(sq[i][j]=='#'){
                count++;
                j++;
            }
            else if(count!=0){
                break;
            }
            else{
                j++;
            }
        }
        if (count != 0) {
            break;
        }
    }
    if(total != count*count)
    {
        cout << no << "\n";
        continue;
    }
    string result = yes;
    for(int k=i+1;k < i + count;k++){
        for(int l=j-count;l < j;l++){
                if(sq[k][l]!='#'){
                result=no;
                break;
                }
        }
    }
    cout<<result<<endl;
}
}










