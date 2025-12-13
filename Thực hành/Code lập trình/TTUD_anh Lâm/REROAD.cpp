#include <iostream>

using namespace std;

main(){
	int n;
	
	cin >> n;
	
	int t[n], i, d = 1;
	
	for(i = 0; i < n; i++){
		cin >> t[i];
	}
	
	for (i = 1; i < n; i++){
		if (t[i] != t[i-1]) {
			d++;
		}
	}
	
	int q, p, c;
	cin >> q;
	for (i = 0; i < q; i++) {
		cin >> p >> c;
		
		if (p != 1) {
			if ((t[p-1] != t[p - 2]) && (c == t[p-2])) {
				d--;
			}
			if ((t[p-1] == t[p - 2]) && (c != t[p-2])) {
				d++;
			}
		}
		
		if (p != n) {
			if ((t[p-1] != t[p]) && (c == t[p])) {
				d--;
			}
			if ((t[p-1] == t[p]) && (c != t[p])) {
				d++;
			}
		}
		t[p-1] = c;
		
		cout << d << endl;
	}
}
