#include<bits/stdc++.h>

using namespace std;

int a[13][13], n, m, d = 0;
bool c[13], p[25], mi[25];

void f(int x) {
	int i, j, l;
	for (i = 1; i <= n; i++) {
		if (a[x][i] == 0 && c[i] && p[x+i-1] && mi[x-i+n]) {
			if (x == n) {
				d++;
			}else {
				c[i] = false;
				p[x+i-1] = false;
				mi[x-i+n] = false;
				
				f(x+1);
				
				c[i] = true;
				p[x+i-1] = true;
				mi[x-i+n] = true;

			}
			
		}
	}
}

main() {
	int i, j, k, l;
	cin >> n >> m;
	for (i = 1; i <= 12; i++) c[i] = true;
	for (i = 1; i < 2*12; i++) {
		p[i] = true;
		mi[i] = true;
	}
	
	do {
		d = 0;
		if (n > 0) {
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= n; j++)
					a[i][j] = 0;
			}
			
			for (i = 0; i < m; i++) {
				cin >> k >> l;
				a[k][l] = 1;
			}
			
			f(1);
		}
		cout << d << endl;
		cin >> n >> m;
	} while (n != 0 || m != 0);
	
}
