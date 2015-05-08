#include <iostream>
using namespace std;
char arr[105][105];
bool config[105][105][4];
void findSafeConfigs(char *arr) {
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < 4; k++) {
				config[i][j][k]  = 1;
			}
			
		}
	}

}
 
int main() {
	int T;
	int M, N;
	cin >> T;
	while(T--) {
		cin >> M >> N;
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		findSafeConfigs(arr, M, N);
	}
}
