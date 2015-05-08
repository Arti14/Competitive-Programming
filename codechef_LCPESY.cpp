#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int T; 
	string C; 
	string D;
	cin>>T;
	while(T--)
	{
		cin>>C;
		cin>>D;
		sort(C.begin(), C.end());
		sort(D.begin(), D.end());
		int i=0,j=0;
		int count=0;
		while(i<C.length()&&j<D.length())
		{
			if(C[i]==D[j])
			{
				count++;
				i++;
				j++;
			}
			else if(C[i]<D[j])
			{
				i++;
			}
			else 
			{
				j++;
			}

		}
		
		cout<<count;
		cout<<endl;
	}
}