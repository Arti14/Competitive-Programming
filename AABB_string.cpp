#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	int arr[1000001];
	cin>>str;
	arr[0]=0;
	int A=0,B=0;
	int len = str.length();
	for(int i=0; i<str.length(); i++)
	{
		if(str[i]=='A')
		{
			A++;
		}
		if(str[i]=='B')
		{
			B++;
		}
		arr[i+1]=B-A;
	}
	sort(arr, arr+len+1);
	int sum=0;
	for(int i=1; i<len+1;i++)
	{
		int count =0;
		while((arr[i-1]==arr[i])&& i<len+1)
		{
			count++;
			i++;
		}
		sum+=count*(count-1)/2;
	}
	cout<<sum<<endl;

}