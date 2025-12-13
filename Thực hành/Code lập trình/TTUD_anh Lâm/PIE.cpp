#include<bits/stdc++.h>

using namespace std;
double M_PI = 3.14159265358979323846;
main() {
	int t, i;
	cin >> t;
	for (i = 0; i < t; i++) {
		int n, f, j, k, d = 0;
		cin >> n >> f;
		int r[n];
		for (j = 0; j < n; j++) cin >> r[j];
		double l = 0, h = 4e8, m;
		for (j = 0; j < 100; j++) {
			m = (l + h) / 2;
			d = 0;
			for (k = n - 1; k >= 0 && d <= f; --k)
				d += (int)floor(M_PI * r[k] * r[k] / m);
			if (d > f) l = m; else h = m;
		}
		printf("%6f \n", m);
	}
	
}
