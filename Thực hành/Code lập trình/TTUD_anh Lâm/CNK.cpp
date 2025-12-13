#include<bits/stdc++.h>

using namespace std;

main() {
	int t, x;
	cin >> t;
	for (x = 0; x < t; x++) {
		unsigned long long n, m;
		unsigned long long i, j, k;
		unsigned long long s = 1;
		cin >> n >> k >> m;
		k = min(n-k, k);
		for(i = 1; i <= k; i++, n--){
			s = s * n/i % m;
		}
		cout << s << endl;
	}
}
