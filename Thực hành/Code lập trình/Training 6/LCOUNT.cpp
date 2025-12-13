#include <bits/stdc++.h>
#define pb push_back
#define HNT ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
const int Max = 1e5 + 7;

vii a;
int n;
int ans = 0;
bool mark[Max];

void DFS(int u){
    int cnt = 0;
    mark[u] = false;
    for(int v : a[u]){
        if(mark[v]){
            cnt++;
            DFS(v);
        }
    }
    if(cnt == 0) ans++;
}

void solve(){
    cin >> n;
    a.resize(n + 1, vi(0));
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    memset(mark, true, sizeof mark);
    for(int i = 1; i <= n; i++){
        if(mark[i]) DFS(i);
    }
    cout << ans << endl;
}

int main () {
	HNT
    solve();

}
