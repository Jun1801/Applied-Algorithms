#include <iostream>
 
using namespace std;

main(){
    long long int n, a, s = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++){
    	cin >> a;
    	s += a;
    	s = s % 1000000007;
	}
	
	cout << s;
}
