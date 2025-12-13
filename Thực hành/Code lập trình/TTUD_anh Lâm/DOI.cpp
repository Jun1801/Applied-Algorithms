#include<bits/stdc++.h>

using namespace std;

main() {
	int n, i, j, k, d = 0, t = 0;
	cin >> n;
	int a[n];
	for(i = 0; i < n; i++) cin >> a[i];
	for (i = 1; i < n - min(d, t); i++) {
		if (min(i, n-i-1) > t){
			for (j = 1; j <= min(i, n-i-1) && a[i-j]>a[i-j+1] && a[i+j]>a[i+j-1]; j++) 
			t = max(t, j);
		}
		if (min(i, n-i-1) > d){
			for (j = 1; j <= min(i, n-i-1) && a[i-j]<a[i-j+1] && a[i+j]<a[i+j-1]; j++) 
			d = max(d, j);
		}
	}
	cout << d << " " << t;
}
