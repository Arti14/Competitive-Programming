#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#define MAXM 1000
using namespace std;
vector <string> input;
map < string, int > wordMap;
map < string, int > :: iterator it;
vector < int > adj[MAXM];
bool dp[MAXM+1][MAXM+1];

bool isPalindrome(int x, int y, string str) {
	if(x == y) {
		dp[x][y] = true;
		return true;
	}
	if((x+1 == y || x == y) && str[x] == str[y]) {
		dp[x][y] = true;
		return true;
	}
	if(dp[x+1][y-1] && str[x] = str[y]) {
		dp[x][y] = true;
		return true;
	}
	dp[x+1][y-1] = false;
	return false;
}

int main() {
	int N;
	string s;
    while(true) {
    	cin >> N;
    	for(int i = 0; i < N; i++) {
    		cin >> s;
    		input.push_back(s);
    		wordMap[s] += 1;
    		adj[i].clear();
    	}
    	for(int i = 0; i < input.size(); i++) {
    		int len = input[i].length();
    		for(int l = 0; l < len; l++) {
    			dp[l][len] = false;
    		}
    		for(int j = len - 1; j > 0; j--) {
    			//string str = substr(j, len - j);
    			bool flag = isPalindrome(j, len-1, input[i]);
    			if(flag) {
    				string remaining = substr(0, j+1);
    				it = wordMap.find(remaining);
    				if(it != wordMap.end()) {
    				}
    			}
    		}
    	}
    }
 }