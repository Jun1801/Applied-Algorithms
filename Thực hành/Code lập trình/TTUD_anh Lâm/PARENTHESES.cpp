#include <iostream>
#include <string>

using namespace std;

main() {
	int n, i, j;
	string s;
	
	cin >> n;
	
	for (i = 0; i < n; i++){
		cin >> s;
		int a = 0, b = 0, c = 0;
		for (j = 0; j < s.size(); j++){
			if (s[j] == '(') a++;
			if (s[j] == ')') a--;
			if (s[j] == '[') b++;
			if (s[j] == ']') b--;
			if (s[j] == '{') c++;
			if (s[j] == '}') c--;
		}
		if ((a == 0) && (b == 0) && (c == 0)) {
			cout << 1 << endl;
		} else cout << 0 << endl;
	}
	
}
