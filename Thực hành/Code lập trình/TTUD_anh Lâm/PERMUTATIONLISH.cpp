#include<bits/stdc++.h>

using namespace std;

//bool next_permutation(int h[], int n) {
//	int i = n;
//	
//}

main() {
	long long n, i, j = 1, k, l, g, s = 1;
	cin >> n >> k;
	bool f = false;
	for (s = 1; s < n+1; s++) {
		j = j * s;
//		cout << j << " " << s << endl;
		if (j >= k) {
			
			f = true;
			break;
		}
	}
	if (!f) cout << "-1";
	else {
		int h[n];
		for (i = 0; i < n; i++) h[i] = i + 1;
		if (k == 1) {
			for (i = 0; i < n; i++) 
				cout << h[i] << " ";
		}else if (k == j && s == n){
			for (i = n; i > 0; i--)
				cout << i << " ";
		}else {
			
//			for (i = 1; i < k; i++) {
//		        for (g = n-2; g>=0; g--) if (h[g] < h[g+1]) break;                                  
//		        for (l = n-1; l>g; l--) if (h[g] < h[l]) break; 
//		        swap(h[g], h[l]); 
//		        for (l=g+1, j=n-1; l<j; l++, j--) swap(h[l], h[j]);
//		    }
			while (k > 1) {
				j = 1;
				for (s = 1; s < n+1; s++) {
					j = j * s;
					if (j > k) break;
				}
				j = j / s;
				for (l = n-s+1; l <= n-s+k/j; l++)
					swap(h[n-s], h[l]);
				k = k % j;
				
				if (k == 0) prev_permutation(h+n-s, h+n);
				
//				for (i = 0; i < n; i++) 
//					cout << h[i] << " ";
//				cout << endl;
			}
			
		    for (int i = 0; i < n; i++) 
				cout << h[i] << " ";
		}
	}
}
