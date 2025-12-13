#include <bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);

#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vii;
const int Max = 1e5 + 5;

int n, m;
vii a, b;
bool mark[Max];
bool check[Max];
vi c;

void DFS1(int u){
    mark[u] = false;
    for(int v : a[u]){
        if(mark[v]) {
            DFS1(v);
            c.pb(v);
        }
    }
}

void DFS2(int u){
    mark[u] = false;
    for(int v : b[u]){
        if(mark[v]){
            DFS2(v);
        }
    }
}

void solve(){
    cin >> n >> m;
    a.resize(n + 1, vi(0));
    b.resize(n + 1, vi(0));
    memset(mark, true, sizeof mark);
    memset(check, true, sizeof check);
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        a[x].pb(y);
        b[y].pb(x);
    }
    for(int i = 1; i <= n; i++){
        if(mark[i]){
            DFS1(i);
            c.pb(i);
        }
    }

    memset(mark, true, sizeof mark);
    int ans = 0;
    for(int i = c.size() - 1; i >= 0; i--){
        if(mark[c[i]]) {
            DFS2(c[i]);
            ans++;
        }
    }
    cout << ans << endl;
}

int main () {
    HNT
    solve();
}
