#include <iostream>
#include <string>

using namespace std;

string add0(string x, string y) {
    while (x.size() > y.size()) {
        y = "0" + y;
    }    
    return y;
}

main(){
    string a, b, c, d = "0";
    int i, n = 0;

    cin >> a >> b;

    if (a.size() > b.size()) {
        b = add0(a, b);
    } else a = add0(b, a);

    for(i = a.size()-1; i >= 0; i--){
        int t = (int)a[i] + (int)b[i] - (int)d[0] + n;
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
    
    cout << c << endl;
}
