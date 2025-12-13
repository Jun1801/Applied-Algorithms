#include<bits/stdc++.h>

using namespace std;

main() {
	unsigned long long n, i, k;
	unsigned long long s = 1;
	cin >> k >> n;
	k = min(n-k, k);
	for(i = 1; i <= k; i++, n--){
		s = s * n / i % 1000000007;
	}
	cout << s << endl;
}
