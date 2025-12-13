#include<bits/stdc++.h>

using namespace std;

void QuickSort(long long a[], long long x, long long y) {
	long long i, j, t, mid;
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
			i++;
			j--;
		}
	}while(i < j);
		
	if(x < j) QuickSort(a, x, j);
	if(i < y) QuickSort(a, i, y);
}

void QuickSortd(long long a[], long long x, long long y) {
	long long i, j, t, mid;
	mid = a[(x + y) / 2]; 
	i = x;
	j = y;
	do {
		while(a[i] > mid) i++;
		while(a[j] < mid) j--;
		if(i <= j){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}while(i < j);
		
	if(x < j) QuickSortd(a, x, j);
	if(i < y) QuickSortd(a, i, y);
}

main() {
	int t, i;
	cin >> t;
	for (i = 0; i < t; i++) {
		long long n, j, k = 0, m = 100000000000000000;
		cin >> n;
		long long x[n], y[n];
		for (j = 0; j < n; j++) cin >> x[j];
		for (j = 0; j < n; j++) cin >> y[j];
		QuickSort(y, 0, n-1);
		QuickSortd(x, 0, n-1);
		for (j = 0; j < n; j++) k += x[j]*y[j];
//		while (next_permutation(y, y+n)) {
//			k = 0;
//			for (j = 0; j < n; j++) k += x[j]*y[j];
//			m = min(k, m);
//		}
		cout << "Case #" << i+1 << ": " << k << endl;
	}
}
