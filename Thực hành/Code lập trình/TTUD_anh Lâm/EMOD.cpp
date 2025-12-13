#include <iostream>

using namespace std;

main(){
	int t = 1000000007;
	long long a, b, c = 1;
	
	cin >> a >> b;
	
	for (int i = 0; i < b; i++){
		c = (c * a) % t; 
	}
	
	cout << c;
}
