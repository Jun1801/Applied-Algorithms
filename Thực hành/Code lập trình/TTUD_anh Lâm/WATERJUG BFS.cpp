#include <iostream>
#include <math.h>

using namespace std;

int ucln(int x, int y)
{
    if(y == 0)
        return x;
    else
        return ucln(y, x % y);
}

int move1(int a, int b, int c) {
	int i = 0, j = 0, d = 0;
	do {
		if (i == a) {
			i = 0;
			d++;
		}else if (j == 0) {
			j = b;
			d++;
		}else if (i != a && j != 0) {
			while (i != a && j != 0) {
				d++;
				if(j >= a) {
                    int t = i;
                    i = a;
                    j -= a - t;
                }else  {
                    i += j;
                    j = 0;
                }
			}
		}	
	}while(i != c && j != c);
	
	return d;
}

int move2(int a, int b, int c) {
	int i = 0, j = 0, d = 0;
	do {
		if (i == a) {
			i = 0;
			d++;
		}else if (j == 0) {
			j = b;
			d++;
		}else if (i != a && j != 0) {
			while (i != a && j != 0) {
				d++;
				if(j >= a - i) {
                    int t = i;
                    i = a;
                    j -= a - t;
                }else  {
                    i += j;
                    j = 0;
                }
			}
		}	
	}while(i != c && j != c);
	
	return d;
}

main() {
	int a, b, c, i, j;
	
	cin >> a >> b >> c;
	
	if ((a == c) || (b == c)) {
		cout << "1";
	}else if (c % ucln(a, b) == 0) {
		if (a > b) {
			i = move1(b, a, c);
			j = move2(a, b, c);
			if (i > j) {
				cout << j;
			}else cout << i;
		}else {
			i = move1(a, b, c);
			j = move2(b, a, c);
			if (i > j) {
				cout << j;
			}else cout << i;
		}
	}else cout << "-1";
}
