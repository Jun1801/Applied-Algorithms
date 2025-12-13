#include <iostream>

using namespace std;

bool t[10][30], c[30][30], d[10][30];

void bca(int m, int n, int &s, int x, int b[]) {
	int i, j, a = 0;
	bool f;
	if (x <= n) {
		for (i = 0; i < m; i++) {
			if (t[i][x-1]) {
				f = true;
				for (j = 0; j < n; j++) 
					if (d[i][j] && !c[x-1][j]) {
						f = false;
						break;
					}
				if (f && b[i]+1 < s) {
					b[i]++;
					d[i][x-1] = true;
					bca(m, n, s, x+1, b);
					d[i][x-1] = false;	
					b[i]--;
				} 
			}
		}
	} else {
		for (i = 0; i < m; i++) {
			if (a < b[i]) a = b[i];
		}
		if (a < s) s = a;
	}
}

main() {
	int n, m, i, j, k, l, h, s, a = 0;
	
	cin >> m >> n;
	
	s = n + 1;
	int b[m];
	
	for (i = 0; i < m; i++) {
		cin >> k;
		for (j = 0; j < n; j++) {
			t[i][j] = false;
			d[i][j] = false;
		} 
			
		for (j = 0; j < k; j++) {
			cin >> l;
			t[i][l-1] = true;
		}
		
		b[i] = 0;
	}
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
			c[i][j] = true;
		c[i][i] = false;
	}
	
	cin >> k;
	for(i = 0; i < k; i++) {
		cin >> h >> l;
		c[h-1][l-1] = false;
		c[l-1][h-1] = false;
	}
	
	bca(m, n, s, 1, b);
	
	if (s < n+1) 
		cout << s;
	else cout << "-1";
}
