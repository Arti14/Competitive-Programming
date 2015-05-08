#include<iostream>
using namespace std;
int main() 
{
int arr[10][10];
int b[10]={0};
int m,n;
int sum=0;
int max_sum=0;
cin>>m>>n;
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        cin>>arr[i][j];
    }
}
for(int i=0;i<m;i++)
{
   for(int ix=i;ix<m;ix++)
   {
    sum = 0; 
    for(int j=0;j<n;j++)
    {
            b[j]=b[j]+arr[ix][j];
            sum=sum+b[j];
            if(sum<0)
            {
            sum=0;
            }
            if(max_sum<sum)
            {
                max_sum=sum;
            }
    }
   }
   for(int k=0;k<n;k++)
   {
        b[k]=0;
   }
}
cout<<"max sum is"<<endl;
cout<<max_sum<<endl;
return 0;
}
        

        

