#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct player{
    string name;
    int shot;
    int height;
    int rank;
    };

struct plq{
    string name;
    int rank;
    int time;
    };
plq pl;
int minx(int a, int b) {
    return (a < b)?a : b;
}

class mycomp {
    public:
    bool operator() (const string& lhs, const string& rhs) const {
    for (int i = 0; i < min(lhs.length(), rhs.length()); ++i) {
		if (lhs[i] < rhs[i]) {
		    return true;
		} else if (lhs[i] > rhs[i]) {
		    return false;
		}
	}
	if (lhs.length() <= rhs.length()) {
	    return true;
	}
	return false;
   }
} myobject;

class mycomparison_g
{
  
public:
  
  bool operator() (const plq& lhs, const plq& rhs) const
  {
    if(lhs.time==rhs.time){
        if(lhs.rank>rhs.rank){
            return false;
        }
        else{
            return true;
        } 
    }   
    if (lhs.time > rhs.time) {
        return false;
    }
    return true;
  }
};

class mycomparison_b
{
  
public:
  
  bool operator() (const plq& lhs, const plq& rhs) const
  {
    if(lhs.time==rhs.time){
        if(lhs.rank<rhs.rank){
            return false;
        }
        else{
            return true;
        } 
    }   
    if (lhs.time < rhs.time) {
        return false;
    }
    return true;
  }
};

    
priority_queue <plq,vector< plq >,mycomparison_g> q1_g;  
priority_queue <plq,vector< plq >,mycomparison_b> q1_b;
priority_queue <plq,vector< plq >,mycomparison_g> q2_g; 
priority_queue <plq,vector< plq >,mycomparison_b> q2_b;  
  
player arr[30];

void rank(int n){
    string nm;
    int sh;
    int hgt;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].shot<arr[j].shot){
                nm=arr[i].name;
                arr[i].name=arr[j].name;
                arr[j].name=nm;
                sh=arr[i].shot;
                arr[i].shot=arr[j].shot;
                arr[j].shot=sh;
                hgt=arr[i].height;
                arr[i].height=arr[j].height;
                arr[j].height=hgt;
             }
             if(arr[i].shot==arr[j].shot){
                if(arr[i].height<arr[j].height){
                        nm=arr[i].name;
                        arr[i].name=arr[j].name;
                        arr[j].name=nm;
                        sh=arr[i].shot;
                        arr[i].shot=arr[j].shot;
                        arr[j].shot=sh;
                        hgt=arr[i].height;
                        arr[i].height=arr[j].height;
                        arr[j].height=hgt;
                 }
             }
         }
         arr[i].rank=i+1;
    }
}    
            
    
    
   
int main(){
    int T,N,M,P;
    int index=1;
    cin>>T;
    while(T--){
            cin>>N>>M>>P;
            for(int i=0;i<N;i++){
                arr[i].name="";
                arr[i].shot=0;
                arr[i].height=0;
            }
            for(int i=0;i<N;i++){
                cin>>arr[i].name>>arr[i].shot>>arr[i].height;
            }
            cout<<"Case #"<<index++<<":";
            rank(N);
            if(2*P==N){ // no extra players
                vector<string> choma;
                for(int i=0;i<N;i++){
                    choma.push_back(arr[i].name);
                }
                sort(choma.begin(), choma.end(), myobject);
                for(int i=0;i<N;i++){
                    cout << " " << choma[i];
                }
                cout<<endl;
                continue;
            }    
            
            for(int i=1;i<=2*P;i++){ //priority queue for players on ground

                if(i%2!=0){
                    pl.name=arr[i-1].name;
                    pl.rank=arr[i-1].rank;
                    pl.time=0;
                    q1_g.push(pl);
                }
                else{
                    pl.name=arr[i-1].name;
                    pl.rank=arr[i-1].rank;
                    pl.time=0;
                    q2_g.push(pl);
                }
            }
            
            for(int i=2*P+1;i<=N;i++){ //priority queue for players on bench
                if(i%2!=0){
                    pl.name=arr[i-1].name;
                    pl.rank=arr[i-1].rank;
                    pl.time=0;
                    q1_b.push(pl);
                }
                else{
                    pl.name=arr[i-1].name;
                    pl.rank=arr[i-1].rank;
                    pl.time=0;
                    q2_b.push(pl);
                }
            }
            int min=0; 
            plq tmp1,tmp2;
            queue < plq > tmpq1; 
            queue < plq > tmpq2;     
            while(min<M){
		   for(int i=0;i<P;i++){
                        tmp1=q1_g.top();
                        tmp1.time++;
                        q1_g.pop();
                        tmpq1.push(tmp1);
            
                    }
                    for(int i=0;i<P;i++){
                        tmp2=q2_g.top();
                        tmp2.time++;
                        q2_g.pop();
                        tmpq2.push(tmp2);
            
                    }    
                     for(int i=0;i<P;i++){
                        tmp1=tmpq1.front();
                        q1_g.push(tmp1);
                        tmpq1.pop();
                        tmp2=tmpq2.front();
                        q2_g.push(tmp2);
                        tmpq2.pop();
                    }
            
                    tmp1=q1_g.top();
                    q1_g.pop();
                    q1_g.push(q1_b.top());
                    q1_b.pop();
                    q1_b.push(tmp1);
                   
                    tmp2=q2_g.top();
                    q2_g.pop();
                    q2_g.push(q2_b.top());
                    q2_b.pop();
                    q2_b.push(tmp2);
                    
                    min++;
           }
         vector<string> v;           
         for(int i=0;i<P;i++){
            v.push_back(q1_g.top().name);
            q1_g.pop();  
         }
         for(int i=0;i<P;i++){
            v.push_back(q2_g.top().name);
            q2_g.pop();  
         }       
	 sort(v.begin(), v.end(), myobject);
	 for (int i = 0; i < v.size(); ++i) {
		cout << " " << v[i];
	}
         while(!q1_b.empty()){
            q1_b.pop();
         }
         while(!q2_b.empty()){
            q2_b.pop();
         }
       cout<<endl;         
    }
     
}            





