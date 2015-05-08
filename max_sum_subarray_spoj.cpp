#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector < int > arr;
int st[100000][4];
int getMid(int x, int y)
{
	return (x+y)/2;
}

int* query(int ss,int se, int l, int r, int index)
{
	int *temp = new int[4];
	if(se<l)
	{
		for (int i = 0; i < 4; ++i) {
			temp[i] = -15007;
		}
		
		return temp;
	}
	if(ss>r)
	{
		for (int i = 0; i < 4; ++i) {
			temp[i] = -15007;
		}
		
		return temp ;
	}
	if(ss>=l && se<=r)
	{
         temp[0]=st[index][0];
         temp[1]=st[index][1];
         temp[2]=st[index][2];
         temp[3]=st[index][3];
         cout<<" index "<<index<<endl;
         return temp;
	}
	int mid=getMid(ss, se);
	int *tl, *tr;
	tl=query(ss,mid,l,r,2*index+1);
	tr=query(mid+1,se,l,r,2*index+2);
 	cout<<" index "<<index<<endl;
	cout<<" tl[0] "<<tl[0]<<" tr[0] "<<tr[0]<<endl;
	cout<<" tl[1] "<<tl[1]<<" tr[1] "<<tr[1]<<endl;
	cout<<" tl[2] "<<tl[2]<<" tr[2] "<<tr[2]<<endl;
	cout<<" tl[3] "<<tl[3]<<" tr[3] "<<tr[3]<<endl;
	temp[0]=max(tl[0],(tl[2] + tr[0]));
	temp[1]=max(tr[1],(tr[2] + tl[1]));
	if(tr[2]!=-15007&& tl[2]!=-15007)
	{	
		temp[2]=tr[2]+tl[2];
	}
	else
	{
		temp[2]=max(tr[2],tl[2]);
	}
	temp[3]=max(tl[0],tr[0]);
	temp[3]=max(tl[1],temp[3]);
	temp[3]=max(tr[1],temp[3]);
	temp[3]=max(temp[3],(tr[2] + tl[2]));
	temp[3]=max(temp[3],(tl[1]+tr[0]));
	return temp;
}

// 0 prefix sum;
// 1 suffix sum;
// 2 total sum;
// 3 max interval sum;
void makest(int ss, int se, int index)
{
	if(ss>se)
	{
		return ;
	}
	if(ss==se)
	{
		st[index][0]=arr[ss];
		st[index][1]=arr[ss];
		st[index][2]=arr[ss];
		st[index][3]=arr[ss];
		return ;
	}
	int mid=getMid(ss,se);
	int temp_l=2*index+1;
	int temp_r=2*index+2;
	makest(ss, mid,temp_l);
	makest(mid+1,se, temp_r);
	st[index][0]=max(st[temp_l][0],(st[temp_l][2] + st[temp_r][0]));
	st[index][1]=max(st[temp_r][1],(st[temp_r][2] + st[temp_l][1]));
	st[index][2]=st[temp_r][2]+st[temp_l][2];
	st[index][3]=max(st[temp_l][0],st[temp_r][0]);
	st[index][3]=max(st[temp_l][1],st[index][3]);
	st[index][3]=max(st[temp_r][1],st[index][3]);
	st[index][3]=max(st[index][3],(st[temp_r][2] + st[temp_l][2]));
	st[index][3]=max(st[index][3],(st[temp_l][1]+st[temp_r][0]));

}

int main()
{
	int N, x,M;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>x;
		arr.push_back(x);
	}
	makest(0,N-1,0);
	/*cout<<" ST "<<endl;
	for(int i=0;i<2*N-1;i++)
	{
		cout<<i<<" pre sum "<<st[i][0];
		cout<<" suffix sum "<<st[i][1];
		cout<<" total sum "<<st[i][2];
		cout<<" sub sum "<<st[i][3];
		cout<<endl;
	}*/
	cin>>M;
	while(M--)
	{
		int xi, yi;
        int *temp;
        cin>>xi>>yi;
		temp = query(0,N-1, xi-1, yi-1, 0);
		cout<<temp[3]<<endl;
	}
	
}	