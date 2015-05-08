#include <iostream>
#include <cmath>
using namespace std;

int main(){
	while(1){
		double x;
		double q;
		cin>>x>>q;
		double ans;
		ans = pow(x,1/q);
		double ans1 = pow(ans, q);
		cout<<ans<<" "<<ans1<<endl;
	}
}