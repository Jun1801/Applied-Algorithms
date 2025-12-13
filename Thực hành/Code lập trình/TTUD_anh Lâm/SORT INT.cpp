#include <iostream>

using namespace std;

void QuickSort(int a[], int x, int y) {
	int i, j, t, mid;
	mid = a[(x + y) / 2]; 
	i = x;
	j = y;
	do {
		while(a[i] < mid) i++;
		while(a[j] > mid) j--;
		if(i <= j){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}while(i < j);
		
	if(x < j) QuickSort(a, x, j);
	if(i < y) QuickSort(a, i, y);
}

main(){
	int n, i, j;
	
	cin >> n;
	
	int a[n];
	
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	QuickSort(a, 0, n-1);
	
	for (i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

}
