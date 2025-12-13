#include <iostream>

using namespace std;

main(){
	int n, b, i, j, k, h, d = -1, m1, m2;
	
	cin >> n >> b;
	
	int a[n];
	
	for (i = 0; i < n; i++){
		cin >> a[i];
	}
	
	m1 = a[0];
	m2 = a[2];
	h = 2;
	if (n > 3) {
	
		for (j = 3; j < n; j++){
			if (m2 < a[j]) {
				m2 = a[j];
				h = j;
			}
		}
	}
	
	for (i = 1; i < n-1; i++){
		
		if (m1 < a[i - 1]) {
			m1 = a[i - 1];
		}
		
		if (i == h) {
			m2 = a[i + 1];
			for (j = i + 2; j < n; j++){
				if (m2 < a[j]) {
					m2 = a[j];
					h = j;
				}
			}
		}
		
		if ((m1 - a[i] >= b) && (m2 - a[i] >= b)) {
			k = m1 + m2 - 2 * a[i];
			if (k > d) {
				d = k;
			}
		}
	}
	
	cout << d;
}
