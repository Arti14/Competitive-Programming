#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector < int > arr;
int dp[4][8000];

int cnt(int m, int n)
{
	if(n==0)
	{
		return 1;
	}
	if(n<0)
	{
		return 0;
	}
	if (m <=0 && n >= 1)
	{
        return 0;
    }
    if (dp[m][n] == 0) {
        dp[m][n] = cnt(m - 1, n) + cnt(m, n - m);
    }
    return dp[m][n];     
}

int main()
{
    int T;
    int Sp2n[501];
    int count=1;
    for (int i = 0; i < 8000; ++i) {
        for (int j = 0; j < 4; ++j) {
            dp[j][i] = 0;
        }
    }
    cnt(3, 7994);
    for(int i=2;i<7994;i++)
        {
                int j;
                if(count==1)
                {
                    Sp2n[count]=2;
                    count++;
                    continue;
                }
            
                for(j=2;j<=sqrt(i);j++)
                {
                    if(i%j==0)
                    {
                        break;
                    }
                 }
                if(j>sqrt(i)&&(i-1)%4==0)
                {
                    Sp2n[count]=i;
                    count++;
                }
        } 
    
    cin>>T;  
    while(T--)
    {
        int n, k;
        cin>>n>>k;
        int p=cnt(k,Sp2n[n]);
        cout<<p<<endl;
    }
    
}

