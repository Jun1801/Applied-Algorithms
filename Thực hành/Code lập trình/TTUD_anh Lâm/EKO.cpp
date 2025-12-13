#include<bits/stdc++.h>

using namespace std;

void QuickSort(int a[], int x, int y) {
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
			i++;
			j--;
		}
	}while(i < j);
		
	if(x < j) QuickSort(a, x, j);
	if(i < y) QuickSort(a, i, y);
}

main() {
	int n, m, i, j, l = 0, k;
	long long d;
	scanf("%d", &n);
	scanf("%d", &m);
	int h[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	QuickSort(h, 0, n-1);
	j = h[n-1];
	h[-1] = j;
	while (l < j - 1) {
		k = (l + j) / 2;
		d = 0;
		for (i = n-1; h[i] > k; i--) d += (long long)h[i] - (long long)k;
		if (d >= m) l = k; else j = k;
//		cout << k << " " << d << " " << l << endl;
	}
	cout << l;
}
