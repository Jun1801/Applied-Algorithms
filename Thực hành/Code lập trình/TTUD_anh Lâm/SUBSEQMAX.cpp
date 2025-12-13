#include <iostream>
 
using namespace std;
 
main(){
	int n, i, j;
	
	cin >> n;
	
	int s[n], w[n];
	
	for(i = 0; i < n; i++){
		cin >> s[i];
		w[i] = s[i];
		
		if ((i != 0) && (w[i-1] + w[i] > w[i]))  {
			w[i] += w[i-1];
		}
//		cout << s[i] << " " << w[i] << endl;
	}
	
	j = w[0];
	
	for(i = 1; i < n; i++){
		if (j < w[i]) {
			j = w[i];
		}
	}
	
	cout << j;
}
