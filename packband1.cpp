#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <set>

using namespace std;

#define MX 1003

int box[MX], C1[MX], C2[MX], used[MX];
int n, m;

int solve()
{
	int ans = 0;

	sort(box,box+n);

	memset(used,0,sizeof used);
	
	for(int i=0;i<n;i++)
	{
		int mat_ind = -1, mat_fin;

		for(int j=0;j<m;j++)
		{
			if(used[j]) continue;

			if(C1[j]<=box[i] && box[i]<=C2[j])
			{
				if(mat_ind==-1 || C2[j]<mat_fin)
					mat_ind = j, mat_fin = C2[j];
			}
		}

		if(mat_ind!=-1)
		{
			ans++;
			used[mat_ind] = 1;
		}
	}

	return ans;
}


int main()
{
	int t,l,r1,r2; scanf("%d",&t); 
	
	while(t--)
	{
		scanf("%d",&n); 
		for(int i=0;i<n;i++)
		{
			scanf("%d",&l); 
			box[i] = 7 * l;
		}

		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&r1,&r2);
			C1[i] = 11*r1;
			C2[i] = 11*r2;
		}

		printf("%d\n",solve());
	}

	return 0;
}
