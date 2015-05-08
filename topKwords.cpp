#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};
int main(){
	string input[] = {"ab", "abb", "ab", "abcd", "abde"};
	map < string, int > mymap;
	for(int i = 0; i < 5; i++){
		mymap[input[i]] += 1;
	} 
	vector<pair<string, int> > mapcopy(mymap.begin(), mymap.end());
	vector<pair<string, int> > :: iterator it;
	sort(mapcopy.begin(), mapcopy.end(), less_second<string, int>());
	for(it = mapcopy.begin(); it != mapcopy.end(); ++it){
		cout<<it->first<<" "<<it->second<<endl;
	}
}