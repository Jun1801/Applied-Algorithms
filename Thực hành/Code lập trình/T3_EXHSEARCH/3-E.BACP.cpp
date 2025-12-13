//3-E.BACP
#include <iostream>
#define MAX 100
using namespace std;
int a[MAX][MAX], x[MAX], load[MAX] = {0}, c[MAX], n, m, ans = 999999999, maxload = 0;

void input(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> c[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
		}
	}
}

bool check(int v, int k){
	for(int i=1; i<k; i++){
		if(a[i][k] == 1 && x[i]>=v) return false;
		if(a[k][i] == 1 && x[i] <= v) return false; 
	}
	return true;
}

void TRY(int k){
	for(int v=1; v<=m; v++){
		if(check(v, k)){
			x[k] = v;
			load[v]+=c[k];
			if(k==n) {
				maxload = 0;
//				for(int i=1; i<=n; i++){
//					cout << x[i] <<" ";
//				}
//				cout << endl;
				for(int i=1; i<=m; i++){
					maxload = max(maxload, load[i]);
				}
				ans = min(ans, maxload);
			}
			else TRY(k+1);
			load[v] -= c[k];
		}
	}
}

int main(){
	input();
	TRY(1);
	cout << ans;
//	cout << endl << a[4][3];
}
