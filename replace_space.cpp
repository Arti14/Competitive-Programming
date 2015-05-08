#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin>>n;
	int count = 0;
	char *s = (char*)malloc(sizeof(char)*n);
	cin.ignore();
	scanf("%[^\n]s",s);
	//a[n] = '\0';
	for(int i = 0; i < n; i++){
		if(s[i]==' '){
			count++;
		}
	}
	cout<<count<<endl;
	s = (char*)realloc(s,sizeof(char)*(n+(count*2)+1));
	int len = strlen(s);
	int j = len + count*2 - 1;
	for(int i = n-1; i >= 0; i--){
		if(s[i]==' '){
			s[j] = '0';
			s[j-1] = '2';
			s[j-2] = '%';
			j = j - 3;
		} else {
			s[j] = s[i];
			j--;
		}
	}
	s[n+(count*2)] = '\0';
	printf("%s\n",s );
}