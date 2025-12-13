#include <bits/stdc++.h>
using namespace std;
#define HNT  ios_base::sync_with_stdio(false);    cin.tie(0);
const int N = 31, M = 21, K = 31;
int n,m, k;
int c[N][N], cmin = INT_MAX;

int cnt[M];
int ck = 0, copt = INT_MAX;

TRY(int v){
    for(int i = 1; i <= m; i++){
        if(cnt[i] < k){
            ck += c[i][v];
            cnt[i]++;
            if(v == n){
                copt = min(copt, ck);
            }
            else
                if(ck + (n - v)*cmin < copt) TRY(v+1);
            ck -= c[i][v];
            cnt[i]--;
        }
    }
}

int main() {
    HNT;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            cmin = min(cmin, c[i][j]);
        }
    }
    for(int i = 1; i <= m; i++) cnt[i] = 0;
    TRY(1);
    cout << copt;
    return 0;

}
