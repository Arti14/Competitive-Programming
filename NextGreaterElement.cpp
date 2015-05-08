#include <iostream>
#include <stack>
using namespace std;
stack <int> mystack;
int arr[10000];
int nge[10000];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mystack.push(arr[0]);
    int next;
    for(int i = 1; i < n; i++) {
        next = arr[i];
        while(!mystack.empty() && next > mystack.top()) {
            cout << mystack.top() << " - " << next << endl;
            mystack.pop();
        }
        mystack.push(next);
    }
    while(!mystack.empty()) {
        cout << mystack.top() << " - -1" << endl;
        mystack.pop();
    }
    return 0;
}