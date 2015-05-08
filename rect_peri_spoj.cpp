#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector < int > height;
vector < int > width;
int dp[1000][2];

int absl(int x,int y)
{
    if(x>y)
    {
        return x-y;
    }
    else
    {
        return y-x;
    }
}

int max_peri(int n,int i)
{
    if(n==0&&i==0)
    {
        dp[n][i]=width[n];
        return width[n];
    }
    if(n==0&&i==1)
    {
        dp[n][i]=height[n];
        return height[n];
        
    }
    if(dp[n][i]!=0)
    {
        return dp[n][i];
    }
    dp[n][0]=max((width[n]+ max_peri(n-1,0)+ absl(height[n],height[n-1])),(width[n]+max_peri(n-1,1)+ absl(height[n],width[n-1])));
    
    dp[n][1]=max((height[n]+ max_peri(n-1,0)+ absl(width[n],height[n-1])),(height[n]+max_peri(n-1,1)+ absl(width[n],width[n-1])));
    return max(dp[n][0],dp[n][1]);
    
}
int main()
{
    int n, h,w;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>h>>w;
        height.push_back(h);
        width.push_back(w);
    }
    int max=max_peri(n-1,0);

    cout<<max;
   
}
    
