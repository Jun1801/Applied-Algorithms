#include<bits/stdc++.h>

using namespace std;

main() {
	int n, m, M, i, j;
	long long q = 0;
	cin >> n >> m >> M;
	int a[n], b[n];
	b[-1] = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = b[i-1] + a[i];
		if (b[i] <= M && b[i] >= m) q++;
		for (j = 0; j < i; j++){
			if (b[i] - b[j] <= M){
				if (b[i] - b[j] >= m) q++;
			}	
		}
	}
	cout << q;
}
