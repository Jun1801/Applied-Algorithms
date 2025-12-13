#include<bits/stdc++.h>

using namespace std;

main() {
	int n, i;
	cin >> n;
	int h[n];
	for (i = 0; i < n; i++) cin >> h[i];
	if (next_permutation(h, h+n)) 
		for (i = 0; i < n; i++) cout << h[i] << " ";
	else cout << "-1";
}
