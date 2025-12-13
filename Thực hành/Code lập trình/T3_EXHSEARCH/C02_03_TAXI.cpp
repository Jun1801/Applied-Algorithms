#include <bits/stdc++.h>
using namespace std;
int a[100][100], x[100], n, ans = INT_MAX;
int main(){
	cin >> n;
	for(int i=0;i<=2*n; i++)
		for(int j=0; j<=2*n; j++)
			cin >> a[i][j];
	for(int i=1; i<=n; i++)
		x[i] = i;
	do
    {
		int cost = 0;
		x[0] = -n;
		for(int i=1; i<=n; i++)
        {
			cost += a[x[i-1]+n][x[i]];
			cost += a[x[i]][x[i]+n];
		}
		ans = min(ans, cost + a[x[n]+n][0]);
	}
	while (next_permutation(x+1,x+1+n));
	cout << ans;
}
