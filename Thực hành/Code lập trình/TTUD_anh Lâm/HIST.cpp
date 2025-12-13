#include <iostream>

using namespace std;

void s(bool a[], bool b[], long long l[], int i, int x, int n, long long & max) {
	int j;
	b[i] = true;
	
	if (!b[i / 2]) {
		s(a, b, l, i / 2, i, n, max);
	}
	if (!b[(i + x) / 2]) {
		s(a, b, l, (i + x) / 2, x, n, max);
	}
	
	if (l[i] > 0 && !a[i]) {
		a[i] = true;
		long long d = l[i]; 
		j = i - 1;
		while (l[j] >= l[i] && j >= 0) {
			if (l[j] == l[i]) a[j] = true;
			d += l[i];
			j--;
		}
		j = i + 1;
		while (l[j] >= l[i] && j < n){
			if (l[j] == l[i]) a[j] = true;
			d += l[i];
			j++;
		}
		if (max < d) {
			max = d;
		}
	}
}

main(){
	int n;
	do {
		cin >> n;
		if (n > 0) {
			int i, m1 = 0, m2 = 0;
			bool a[n], b[n];
			long long max = 0, l[n];
			
			for (i = 0; i < n; i++) {
				cin >> l[i];
				a[i] = false;
				b[i] = false;
			}
			
			s(a, b, l, n / 2, n, n, max);
			cout << max << endl;
		}	
	} while (n > 0);

}
