#include<bits/stdc++.h>

using namespace std;

main() {
	int n, i, j;
	bool f = true;
	cin >> n;
	string h;
	cin >> h;
	for (i = n - 1; i >= 0; i--) {
		if (h[i] == '0'){
			h[i] = '1';
			for (j = i + 1; j < n; j++) h[j] = '0';
			f = false;
			break;
		}
	}
	
	if (!f) 
		for (i = 0; i < n; i++) cout << h[i];
	else cout << "-1";
}
