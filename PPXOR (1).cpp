#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<ctime>
#include<cassert>

using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MP make_pair
#define pb push_back

#define maxn 100000
#define maxv 1000000000

typedef long long  LL;
typedef pair<int,int> pi;
typedef vector<int> vi;


int cnt[70][2],n;

int main()
{
   int i,j,k,T,tot=0;

   scanf("%d",&T);
   assert(T>=1 && T<=maxn);

   while(T--)
   {
      LL ans=0;
      MEM(cnt,0);

      for(i=0;i<30;i++) cnt[i][0]=1;
      scanf("%d",&n);
      assert(n>=1 && n<=maxn);
      tot+=n;
      int sum=0;

      for(j=0;j<n;j++)
      {
         scanf("%d",&k);
         assert(k>=1 && k<=maxv);

         sum^=k;

         for(i=0;i<30;i++)
         {
            LL p=(1<<i);

            if(sum&(1<<i))
               ans+=p*cnt[i][0];
            else
               ans+=p*cnt[i][1];
         }

         for(i=0;i<30;i++)
         {
            if(sum&(1<<i))
               cnt[i][1]++;
            else
               cnt[i][0]++;
         }
      }
      cout<<ans<<endl;
   }

   assert(tot>=1 && tot<=maxn);
	return 0;
}


