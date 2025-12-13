#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);

#define ll long long
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int Max = 1e5 + 7;

vii a;
int n, m;
bool mark[Max];

void DFS(int u){
    mark[u] = true;
    for(int v : a[u]){
        if(!mark[v]) DFS(v);
    }
}

void solve(){
    cin >> n >> m;
    a.resize(n + 1, vi(0));
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    memset(mark, false, sizeof mark);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!mark[i]){
            DFS(i);
            ans++;
        }
    }
    cout << ans << endl;
}

int main () {
	HNT
	solve();
	return 0;
}
