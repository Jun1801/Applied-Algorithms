#include <iostream>

using namespace std;

void t(int a[], int c[], int x, int n, int b, int &max, int &s1, int &s2) {
	int i, j, k;
	for (i = x; i < n; i++) {
		if (a[i] + s1 <= b) {
			s1 += a[i];
//			d[i] = false;
			s2 += c[i];
			if (s2 > max) max = s2;
			t(a, c, i + 1, n, b, max, s1, s2);
			s2 -= c[i];
			s1 -= a[i];
//			cout << s2 << endl;
//			d[i] = true;
		}
	}
}

main() {
	int n, b, i;
	int max = 0, s1 = 0, s2 = 0;
	
	cin >> n >> b;
	
	int a[n], c[n];
//	bool d[n];
	
	for (i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
//		d[i] = true;
	}
	
	t(a, c, 0, n, b, max, s1, s2);
	
	cout << max;
}
