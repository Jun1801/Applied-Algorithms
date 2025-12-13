#include <iostream>
#include <limits.h>

using namespace std;

int c[16], a[16][16], b[5], d[16], s[16];

void dk(int x, int n, int &t) {
	int i, j;
	for (i = 0; i < n; i++) {
		if (a[i][x] == 1 && d[i] == 0) {
			dk(i, n, t);
		}
			
	}
	d[x] = 1;
	s[t] = x;
	t++;
}

void bacp(int x, int n, int m, int &min) {
	int i, j, f = 1, k, l;
	bool h = true;
	for (i = 0; i < m; i++) {
		f = 1;
		for (j = 0; j < n; j++) {
			if (a[j][s[x]] == 1) {
				if (d[j] >= i) {
					f = 0;
					break;
				}
			}
		}
		if (f == 1) {
			b[i] += c[s[x]];
			d[s[x]] = i;
//			cout << x  << "  " << b[0] << " " << b[1] << endl;
			
					
			if (x < n-1) 
				bacp(x+1, n, m, min);
			else{ 
				j = 0;
				for (l = 0; l < m; l++) {
					if (b[l] > j) j = b[l];
				}
				
				if (j < min) min = j;
//					cout << min << "  " << b[0] << " " << b[1] << endl;
			}
			d[s[x]] = -1;
			b[i] -= c[s[x]];
		} 
//	d[x] = -1;
	} 

	
}

main() {
	int n, m, i, j, min = INT_MAX, t = 0;
	
	cin >> n >> m;
	
	for (i = 0; i < m; i++)
		b[i] = 0;
	for(i = 0; i < n; i++) {
		s[i] = 0;
		d[i] = 0;	
	}
		
	
	for (i = 0; i < n; i++)
		cin >> c[i];
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> a[i][j];
	
	for (i = 0; i < n; i++) {
		if (d[i] == 0) {
			dk(i, n, t);	
		}
	}
	
	for (i = 0; i < n; i++)
		d[i] = -1;
	bacp(0, n, m, min);
//	for (i = 0; i < n; i++) 
//		cout << s[i] << " ";
//	cout << endl;
	
	cout << min;
}
