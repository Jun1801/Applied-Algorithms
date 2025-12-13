#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);   cin.tie(0);

int n, L1, L2;
long long a[100001];

void input(){
	cin >> n >> L1 >> L2;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}

void sol(){
	long long ans = 0;
	long long x[100001] = {0};
	for(int i = 0; i < L1; i++){
		x[i] = a[i];
	}

	for(int i = L1; i < n; i++){
		for(int j = i - L2; j <= i - L1; j++){
			if(j >= 0){
				x[i] = max(x[i], a[i] + x[j]);
			}
		}
	}

	for(int i = n - L1; i < n; i++){
		ans = max(ans, x[i]);
	}
	cout << ans;
}

int main(){
    HNT;
	input();
	sol();
	return 0;
}
