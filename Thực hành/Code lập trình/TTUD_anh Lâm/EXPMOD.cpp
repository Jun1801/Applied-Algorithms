#include <iostream>
#include <string>
 
using namespace std;

string add0(string x, string y) {
    while (x.size() > y.size()) {
        y = "0" + y;
    }    
    return y;
}

string add (string x, string y){
	string c;
	int n = 0;
	
	if (x.size() > y.size()) {
        y = add0(x, y);
    } else x = add0(y, x);
    
	for (int i = x.size() - 1; i >= 0; i--){
	        int t = (int)x[i] + (int)y[i] - 48 + n;
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
	return c;
}

bool ss(string x, string y){
	if (x.size() < y.size()) { 
		return false;
	}
	if (x.size() > y.size()) { 
		return true;
	}
	if (x >= y) {
		return true;
	}
	return false;
}

string mod(string x){
	string d = "1000000007";
	int i, t, n = 0;
	while (ss(x, d)) {
		while (x.size() > d.size()) {
        d = d + "0";
    	}
		for(i = x.size()-1; i >= 0; i--){
			if (x[i] < d[i] + n) {
				t = (int)x[i] - (int)d[i] + 48 - n + 10;
				n = 1;
			}else {
	        	t = (int)x[i] - (int)d[i] + 48 - n;
	        	n = 0;
	    	}
	    	x[i] = (char)t ;
	    }
	    d = "1000000007";
	    while ((x[0] == 48) && (x.size() != 1)) { 
			x.erase(x.begin());
		}
	}
	return x;
}

string exp(string x, string y){
	int i, j, k;
	string c, exp = "";
	for (i = 0; i < x.size(); i++){
		c = "";
		for (j = 0; j < ((int)x[i] - 48); j++){
			c = add(y, c);
		}
		for (j = 0; j < (x.size() - i - 1); j++){
			c = c + "0";
		}
		exp = add(exp, c);
	}	 
	return exp;
}

main(){
    string a, e;
    int i, b;
 
    cin >> a;
    cin >> b;
 	
 	e = a;
 	if ((a != "0") && (a != "1")){
	
	 	for (i = 0; i < (b - 1); i++){
			e = mod(exp(e,a));
	//		cout << e << endl;
		}
	}
    cout << e << endl;
}
