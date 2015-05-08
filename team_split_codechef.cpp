#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
static int arr[3000000];
static int precompute1[1000000];
int main()
{
    int T;
    scanf("%d", &T);
    for(int i=0;i<1000000;i++)
    {
            long long v=i;
            precompute1[i]=(v*v)%1000000;
    }
    while(T--)
    {
        int N, a,b,c,d;
        int ans=0;
        
        scanf("%d %d %d %d %d ", &N, &a, &b ,&c, &d);
        if(N==1)
        {
            cout<<d<<endl;
            continue;
        }
        arr[0]=d;
        int precompute[1000000];

        
        for(int i=0;i<1000000;i++)
        {
            long long v = precompute1[i];
            precompute[i]=(v*a+i*b+c)%1000000;
        }
        for(int i=1;i<N;i++)
        {
            int x=arr[i-1];
            arr[i]=precompute[x];
        }
        long long s1=0;
        long long s2=0;
        sort(arr, arr+N);
        for(int i=0;i<N;i++)
        {
            if(i%2==0)
            {
                s1+=arr[i];
            }
            else
            {
                s2+=arr[i];
            }
        }
        if(s1>s2)
        {
        	ans=s1-s2;
        }
        else
        {
        	ans=s2-s1;
        }
        
        cout<<ans<<endl;
    }
}