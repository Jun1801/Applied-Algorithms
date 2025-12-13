#include <iostream>
#include <math.h>

using namespace std;

void QuickSort(int a[], int m[], int x, int y) {
	int i, j, t, mid;
	mid = a[(x + y) / 2]; 
	i = x;
	j = y;
	do {
		while(a[i] < mid) i++;
		while(a[j] > mid) j--;
		if(i <= j){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			t = m[i];
			m[i] = m[j];
			m[j] = t;
			i++;
			j--;
		}
	}while(i < j);
		
	if(x < j) QuickSort(a, m, x, j);
	if(i < y) QuickSort(a, m, i, y);
}

main() {
	int n, k, i, j = 0;
	unsigned long long t = 0, t1 = 0;
	
	cin >> n >> k;
	
	int a[n], m[n];
	
	for (i = 0; i < n; i++) {
		cin >> a[i] >> m[i];
		if (m[i] >= k){
			t += ((unsigned long long)abs(a[i]) * 2 * ((unsigned long long)m[i] / (unsigned long long)k)) / 1000000;	
			t1 += ((unsigned long long)abs(a[i]) * 2 * ((unsigned long long)m[i] / (unsigned long long)k)) % 1000000;
			m[i] = m[i] % k;
		}
	}
	
	QuickSort(a, m, 0, (n - 1));
	
	for (i = 0; i < n; i++) {
		if ((a[i] < 0) && (m[i] != 0)){
			if (j == 0) {
				t += 2 * (unsigned long long)abs(a[i]) / 1000000;
				t1 += 2 * (unsigned long long)abs(a[i]) % 1000000;
				j = k;
			}
			if (j >= m[i]) {
				j -= m[i];
			}else {
				m[i] -= j;
				j = k - m[i];
				t += 2 * (unsigned long long)abs(a[i]) / 1000000;
				t1 += 2 * (unsigned long long)abs(a[i]) % 1000000;
			}
		}
		if (a[i] >= 0) break;
	}
	
	j = 0;
	for (i = n-1; i > -1; i--) {
		if ((a[i] > 0) && (m[i] != 0)){
			if (j == 0) {
				t += 2 * (unsigned long long)abs(a[i]) / 1000000;
				t1 += 2 * (unsigned long long)abs(a[i]) % 1000000;
				j = k;
			}
			if (j >= m[i]) {
				j -= m[i];
			}else {
				m[i] -= j;
				j = k - m[i];
				t += 2 * (unsigned long long)abs(a[i]) / 1000000;
				t1 += 2 * (unsigned long long)abs(a[i]) % 1000000;
			}
		}
		if (a[i] <= 0) break;
	}
	
	if (t1 >= 1000000) {
		t += t1 / 1000000; 
		t1 = t1 % 1000000;
	}
	
	if (t > 0) {
		cout << t;
		for (i = 5; i >= 0; i--) {
			cout << t1 / (int)pow(10, i);
			t1 = t1 % (int)pow(10,i);
		}
	}else cout << t1;
}
