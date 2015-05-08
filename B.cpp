#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int r, x, y, xp, yp;
	cin >> r >> x >> y >> xp >> yp;
	double d = (x - xp) * (x - xp) + (y - yp) * (y - yp);
	d = d / (4 * r * r);
	d = sqrt(d);
	int res = (int) d;
	if (d - (int) d > 0) {
		res = res + 1;
	}
	cout << res << "\n";
	return 0;
}