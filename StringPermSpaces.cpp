//Print all possible strings that can be made by placing spaces
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

void printPattern(char str[], char buff[], int i, int j, int len) {
	if(i == len) {
		buff[j] = '\0';
		cout << buff << endl;
		return;
	}
	buff[j] = str[i];
	printPattern(str, buff, i+1, j+1, len);
	
	buff[j] = ' ';
	buff[j+1] = str[i];
	printPattern(str, buff, i+1, j+2, len);
}
int main() {
	char *str = (char*)malloc(100);
	scanf("%s", str);
	cerr << str << endl;
	int n = strlen(str);
	char buff[2*n];
	buff[0] = str[0];
	printPattern(str, buff , 1, 1, n);
	return 0;
}