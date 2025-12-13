#include<bits/stdc++.h>

using namespace std;

string s;
int d = 0, m = 0, k = 0;
int Try(int x) {
	int i, j = d;
//	if (m < s.size() /2){
		s[x] = '(';
		d++;
		m++;
		for (i = x+1; i < s.size(); i++) {
			if (s[i] == '(') {
				m++;
				if (m > s.size()/2) break;
				d++;
			}
			if (s[i] == ')') {
				d--;
				if (d < 0) {
					break;
				}
			}	
			if (s[i] == '?') {
				Try(i);
				break;	
			}
			
		}
		cout << s << " " << i << " " << d << " " << m << endl;
		if (i == s.size() && d == 0) k = (k + 1) % 1000000007;
//	}
	
	if (j > 0) {
		d = j - 1;
		s[x] = ')';
		for (i = x+1; i < s.size(); i++) {
			if (s[i] == '(') {
				m++;
				if (m > s.size()/2) break;
				d++;
			}
			if (s[i] == ')') {
				d--;
				if (d < 0) {
					break;
				}
			}	
			if (s[i] == '?') {
				Try(i);
				break;	
			}	
					
		}
		cout << s << " " << i << " " << d << " " << m << endl;
		if (i == s.size() && d == 0) k = (k + 1) % 1000000007;
	}
	
}

main() {
	int i, j;
	cin >> s;
	if (s.size() % 2 == 1) cout << 0;
	else {
		for (i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				m++;
				if (m > s.size()/2) break;
				d++;
			}
			if (s[i] == ')') {
				d--;
				if (d < 0) {
					break;
				}	
			}
			if (s[i] == '?') {
				Try(i);
				break;	
			}
		}
		cout << k;
	}
}
