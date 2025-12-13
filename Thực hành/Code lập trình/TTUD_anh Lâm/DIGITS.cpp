#include <iostream>

using namespace std;

bool check (int a[], int n) {
	int x = 100 * a[0] + 10 * a[1] + a[2] - 100 * a[3] - 62 + 1000 * a[4] + 100 * a[5] + 10 * a[6] + a[2];
	if (x == n) return true;
	return false;
}

void digits(int n, int &d) {
	int a[7], i, j, k, h;
	bool f = true, b[10];
	for (i = 1; i < 10; i++) 
		b[i] = true;
	for (i = 0; i < 7; i++) {
		a[i] = i + 1;
		b[i + 1] = false;
	}

	while (true) {
		if (check(a, n)) d++;
		f = true;
		i = 9;
		j = 0;
		while (j < 7) {
			if (a[j] != i) {
				f = false;
				break;
			}
			i--;
			j++;
		}
		 
		if (f) break;
		
		for (i = 6; i >= 0; i--) {
			b[a[i]] = true;
			for (j = 9; j > 0; j--)
				if (b[j]) break;
			if (a[i] < j) {
				for (k = a[i]+1; k < 10; k++)
					if(b[k]) break;
				a[i] = k;
				b[a[i]] = false;
				k = 0;
				h = i+1;
				while (h < 7) {
					k++;
					if (b[k]) {
						a[h] = k;
						b[a[h]] = false;
						h++;
					}
				}	
				break;
			}
		}
	}
}

main() {
	int n, d = 0;
	
	cin >> n;
	
	digits(n, d);
	
	cout << d;
}
