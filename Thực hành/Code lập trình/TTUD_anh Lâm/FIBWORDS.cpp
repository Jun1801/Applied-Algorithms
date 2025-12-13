#include<bits/stdc++.h>

using namespace std;

main() {
	int n, p, i, j, k = 0, c;
	string s;
	unsigned long long d, d1, d2, d3, d4;
	string f, f1, f2;
	getline(cin, s);
	if (s != "") {
		n = atoi (s.c_str());
		getline(cin, s);
		k++;
	} else n = -1;
	while (n >= 0) {
		p = s.size();
		f1 = '0';
		f2 = '1';
		d1 = 0;
		d2 = 0;
		bool a = true, b = true;
		if (p == 1) {
			if (s == f1) d1 = 1;
			else d2 = 1;
			for (i = 2; i <= n; i++) {
				d = d1 + d2;
				d1 = d2;
				d2 = d;
			}
		}else if (p == 0) d = 0;
		else{
			for (i = 2; i <= n; i++) {
				d = d1 + d2;
				if (f1.size() + f2.size() > p) {
					if (a) {
						f = f2 + f1;
						d3 = 0;
						for (j = f2.size() - p + 1; j < f2.size(); j++) {
							if (j >= 0 && j + p <= f.size()) 
								if (s == f.substr(j, p)) d3++;
//							cout << f.substr(j, p) << endl;
						}
						d += d3;
						d1 = d2;
						d2 = d;
//						cout << d << " a " << d3 << endl; 
						f1 = f2;
						f2 = f;
//						cout << f << endl;
						a = false;
						c = i % 2;
					}else if (b) {
						f = f2 + f1;
						d4 = 0;
						for (j = f2.size() - p + 1; j < f2.size(); j++) {
							if (j >= 0 && j + p <= f.size()) 
								if (s == f.substr(j, p)) d4++;
//							cout << f.substr(j, p) << endl;
						}
						d += d4;
						d1 = d2;
						d2 = d;
//						cout << d << " " << d4 << endl; 
						b = false;
//						f1 = f2;
//						f2 = f;
					}else {
						if (c == i % 2) d += d3; else d += d4;
						d1 = d2;
						d2 = d;
//						cout << d << endl; 
					}
				}else if (f1.size() + f2.size() == p) {
					f = f2 + f1;
					if (f == s) d++;
					d1 = d2;
					d2 = d;
//					cout << d << endl; 
					f1 = f2;
					f2 = f;
//					cout << f << endl;
				}	
				else {
					f = f2 + f1;
					f1 = f2;
					f2 = f;
					d1 = d2;
					d2 = d;
//					cout << d << endl; 
//				}else {
//					f2 = f.substr(f.size()-p+1);
//					f1 = f0;		
//				cout << f << endl;
				}
			}
		}
//		cout << f << endl;
		cout << "Case " << k << ": " << d << endl;
		getline(cin, s);
		if (s != "") {
			n = atoi (s.c_str());
			getline(cin, s);
			k++;
		} else n = -1;
	}
	
	
}

