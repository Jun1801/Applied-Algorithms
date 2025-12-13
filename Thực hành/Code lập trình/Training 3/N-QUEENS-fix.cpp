#include<bits/stdc++.h>
#define HNT   ios_base::sync_with_stdio(false);   cin.tie(0);
using namespace std;

const int N = 12;

int a[N + N], b[N + N], c[N], h[N][N];
int n, m, res;

void go(int u) {
    if (u == n) {
        res++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if(!c[i] && !a[u + i] && !b[u - i + N] && !h[u][i]) {
            c[i] = a[u + i] = b[u - i + N] = 1;
            go(u + 1);
            c[i] = a[u + i] = b[u - i + N] = 0;
        }
    }
}
int main() {
    HNT;
    while(cin>>n>>m) {
        if(n == 0) break;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        memset(h, 0, sizeof h);

        for (int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            if(x > 0 && y > 0) h[--x][--y] = 1;
        }
        res = 0;
        go(0);
        cout << res <<endl;
    }
    return 0;
}
