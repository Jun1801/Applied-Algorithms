#include <iostream>
#include <limits.h>

using namespace std;

int a[20][20], b[20], dmin = INT_MAX, n, s = 0, minf = INT_MAX;
bool c[20];

void f(int x) {
	int i, j, k;
	for (i = 1; i < n; i++) {
		if (a[b[x - 1]][i] < INT_MAX && c[i]) {
			b[x] = i;
			c[i] = false;
			s += a[b[x - 1]][i];
			if (x == n-1) {
				if (a[b[x]][0] < INT_MAX) {
					if (s + a[b[x]][0] < minf) 
						minf = s + a[b[x]][0];
				}
			}else {
				if (s + dmin * (n - x) < minf) {
					f(x + 1);
//					cout << x+1 << " " << s << endl;	
				}
			}
			s -= a[b[x -1]][i];
			c[i] = true;
		}
	}
	
}

main() {
	int m, i, j, x, y, z;
	
	cin >> n >> m;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) 
			a[i][j] = INT_MAX;
		a[i][i] = 0;
		c[i] = true;
	}
	for (i = 0; i < m; i++) {
		cin >> x >> y >> z;
		a[x-1][y-1] = z;
		if (dmin > z) dmin = z;
	}
	
	c[0] = false;
	b[0] = 0;
	f(1);
	
	cout << minf;
}
