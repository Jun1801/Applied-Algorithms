#include <bits/stdc++.h>
using namespace std;
#define HNT  ios_base::sync_with_stdio(false);    cin.tie(0);

int main(){
    HNT;
    int n,m;
    cin >> n >> m;
    int a[n+1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int f[n+1][m+1];
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i]; j <= m; ++j) {
            for (int k = j - a[i]; k >=0; k -= a[i]){
                (f[i][j] += f[i - 1][k]) %= 1000000007;
            }
        }
    }
    cout << f[n][m];
    return 0;
}
