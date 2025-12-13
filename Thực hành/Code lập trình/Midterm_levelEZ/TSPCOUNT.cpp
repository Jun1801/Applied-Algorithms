#include <bits/stdc++.h>
using namespace std;
#define HNT  ios_base::sync_with_stdio(false);    cin.tie(0);

int a[16][16], x[16];
int cur = 0, n, m, ans = 0, cmin = INT_MAX;
int  mark[16];

void TRY(int k) {
    for(int i = 2; i <= n ;i++) {
        if(!mark[i]){
            mark[i] = 1;
            x[k] = i;
            cur += a[x[k-1]][i];
            if(k == n){
                if(cur + a[x[k]][1] <= m) ans++;
            }
            else
                if (cur + (n - k + 1)*cmin <= m) TRY(k+1);
            cur -= a[x[k-1]][i];
            mark[i] = 0;
        }
    }
}

int main() {
    HNT;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j]){
                cmin = (cmin > a[i][j])? a[i][j]:cmin;
            }
        }
    }
    for (int i = 1; i <= n; i++) mark[i] = 0;
    x[1] = 1;
    TRY(2);
    cout << ans;
    return 0;
}
