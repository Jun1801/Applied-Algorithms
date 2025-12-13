#include <iostream>
#include <limits.h>

using namespace std;

int a[23][23], b[12];
bool c[12];

void f(int &s, int &min, int x, int n) {
	int i = 0, j, k;
	if (x == n) {
		if (a[b[x-1]][i] < INT_MAX) {
			if (s + a[b[x-1]+n-1][i] < min) 
				min = s + a[b[x-1]+n-1][i];
		}
	}else {
		for (i = 1; i < n; i++) {
			if (i != b[x - 1] && c[i]) {
				b[x] = i;
				c[i] = false;
				if (b[x-1] != 0) s += a[b[x - 1]+n-1][i] + a[i][i+n-1];
				else s = s + a[0][i] + a[i][i+n-1];
				if (s < min) f(s, min, x + 1, n);
				if (b[x-1] != 0) s = s - a[b[x - 1]+n-1][i] - a[i][i+n-1];
				else s = s - a[0][i] - a[i][i+n-1];
				c[i] = true;
			}
		}
	}
	
}

main() {
	int n, m, i, j, x, y, z, s = 0, min = INT_MAX;
	
	cin >> n ;
	
	for (i = 0; i < n+1; i++) {
		c[i] = true;
	}
	for (i = 0; i < 2*n+1; i++) {
		for (j = 0; j < 2*n+1; j++)
			cin >> a[i][j];
	}
	
	c[0] = false;
	b[0] = 0;
	f(s, min, 1, n+1);
	
	cout << min;
}
