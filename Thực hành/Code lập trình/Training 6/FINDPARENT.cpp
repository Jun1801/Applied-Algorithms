#include <bits/stdc++.h>
#define pb push_back
#define HNT ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
const int Max = 1e5 + 7;

vii a, b;
int p[Max];
int n, m;
bool mark[Max];


void DFS(int u){
    mark[u] = false;
    for(int v : a[u]){
        if(mark[v]){
            p[v] = u;
            DFS(v);
        }
    }
}

void solve(){
    cin >> n;
    int ans = 0;
    a.resize(n + 1, vi(0));
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    memset(mark, true, sizeof mark);
    for(int i = 1; i <= n; i++){
        if(mark[i]) DFS(i);
    }
    for(int i = 2; i <= n; i++) cout << p[i] << " ";
}

int main () {
	HNT
    solve();
}
