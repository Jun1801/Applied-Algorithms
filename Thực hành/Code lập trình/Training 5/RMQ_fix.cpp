#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
const int MAX_M = 31;
#define HNT  ios_base::sync_with_stdio(false);    cin.tie(0);

int a[N];
int n, m;
int M[MAX_M][N];

int ans;
int rmq(int i, int j) {
    int k = log2(j-i+1);
    if (a[M[k][i]] < a[M[k][j-(1<<k)+1]]) {
        return a[M[k][i]];
    }
    else {
        return a[M[k][j-(1<<k)+1]];
    }
}
void preprocessing() {
    for (int i = 0; i < n; i++) M[0][i] = i;
    for (int j = 1; (1<<j) <= n; j++) {
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {
            if (a[M[j-1][i]] < a[M[j-1][i + 1 << (j-1)]]){
                M[j][i] = M[j-1][i];
            }
            else {
                M[j][i] = M[j-1][i + (1 << (j-1))];
            }
        }
    }
}
int main () {
    HNT;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    preprocessing();

    cin >> m;
    ans = 0;
    int i,j;
    for (int k = 1; k <= m; k++) {
        cin >> i >> j;
        ans += rmq(i,j);
    }
    cout << ans;
}
