#include <iostream>
#include <string>
using namespace std;

bool ss(string x, string y){
	if (x.size() < y.size()) { 
		return false;
	}
	if (x.size() > y.size()) { 
		return true;
	}
	if (x > y) {
		return true;
	}
	return false;
}

string add0(string x, string y) {
    while (x.size() > y.size()) {
        y = "0" + y;
    }    
    return y;
}

main(){
	string a, b, c, d = "1000000007";
	int n, i, t;
	
	cin >> a >> b;
	
	n = 0;
	if (a.size() > b.size()) {
        b = add0(a, b);
    } else a = add0(b, a);

    for(i = a.size()-1; i >= 0; i--){
        int t = (int)a[i] + (int)b[i] - 48 + n;
        if (t < 58) {
			c = (char)t + c;
			n = 0;
		}else { t = t - 10;
		  		c = (char)t + c;
		  		n = 1;
		  }
    }
    
    if (n == 1) {
		c = "1" + c;
	}
	
	while (ss(c, d)) {
		while (c.size() > d.size()) {
        d = d + "0";
    	}
		for(i = c.size()-1; i >= 0; i--){
			if (c[i] < d[i] + n) {
				t = (int)c[i] - (int)d[i] + 48 - n + 10;
				n = 1;
			}else {
	        	t = (int)c[i] - (int)d[i] + 48 - n;
	        	n = 0;
	    	}
	    	c[i] = (char)t ;
	    }
	    d = "1000000007";
	    while (c[0] == 48) { 
			c.erase(c.begin());
		}
	}
	
	cout << c;
}
