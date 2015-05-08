#include<iostream>
#include<map>
#include<cmath>
using namespace std;

map <int, int> mymap;
map<int,int>::iterator it;

int absl(int x, int y)
{
    if(x>=y)
    {
        return x-y;
    }
    else
    {
        return y-x;
    }
}

int main()
{
    long long A, B;
    int index=1;
    
    cin>>A>>B;
    while(A*B>1)
    {
        int space=0;
        int dist=0;
       
        for(int i=2;i<=sqrt(A);i++)
        {
            int cnt1=0;
            while((A%i==0)&&A>1)
            {
                cnt1++;
                A=A/i;
            }
            if(cnt1!=0)
            {
                 mymap[i]=cnt1;     
            }
        }
        if(A>1)
        {
            mymap[A]=1;
        }
        
        for(int i=2;i<=sqrt(B);i++)
        {
            int cnt2=0;   
            while((B%i==0)&&B>1)
            {
                cnt2++;
                B=B/i;
            }
            if(cnt2!=0)
            {
                if(mymap.count(i)){

                    mymap[i]=absl(mymap[i],cnt2);
                }
                else
                {
                    mymap[i]=cnt2;
                }
            }
            
        }
        if(B>1)
        {
            if(mymap.count(B))
            {
                mymap[B]=mymap[B]-1;
            }
            else
            {
                mymap[B]=1;
            }
        }
        for(it=mymap.begin();it!=mymap.end();++it)
        {
            
            dist=dist+it->second;
            space++;
        }
        cout<<index++<<". "<<space<<":"<<dist<<endl;
        mymap.clear();
        cin>>A>>B;
    }
   
}
    