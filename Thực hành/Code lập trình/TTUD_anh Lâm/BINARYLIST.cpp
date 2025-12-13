#include<bits/stdc++.h>

using namespace std;

main() {
	int n, i, j, k, m, d = 1;
	bool f = false;
	cin >> n >> k >> m;
	int h[n];
	for (i = 0; i < n; i++) 
		if ((i+1) % m == 0) h[i] = 1;
		else h[i] = 0;
		
	while (d < k && !f){
		f = true;
		for (i = n - 1; i >= 0; i--) {
			if (h[i] == 0){
				h[i] = 1;
				for (j = i + 1; j < n; j++) 
//					if ((j - i) % m == 0) h[j] = 1;
					h[j] = 0;
				for (j = 1; i + j * m < n; j++) h[i + j * m] = 1;
				d++; 
				f = false;
				break;
			}
		}
	}
	
	
	if (!f) 
		for (i = 0; i < n; i++) cout << h[i] << " ";
	else cout << "-1";
}
