#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pob pop_back
#define HNT ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int Max = 1e5 + 7;

vii a;
int n, k;
int low[Max], num[Max];
int cnt = 0;
bool numc[Max];
int Count = 0;

void DFS(int u, int p){
    cnt++;
    int numchill = 0;
    num[u] = low[u] = cnt;
    for(int v : a[u]){
        if(v != p){
            if(num[v] != 0)
                low[u] = min(low[u], num[v]);
            else{
                DFS(v, u);
                numchill++;
                low[u] = min(low[u], low[v]);
                if(low[v] >= num[v]) Count++;
                if(u == p){
                    if(numchill >= 2) numc[u] = true;
                }
                else{
                    if(low[v] >= num[u]) numc[u] = true;
                }
            }
        }
    }
}

void solve(){
    cin >> n >> k;
    a.resize(n + 1, vi(0));
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for(int i = 1; i <= n; i++){
        if(!num[i]) DFS(i, i);
    }
    int numcc = 0;
    for(int i = 1; i <= n; i++) if(numc[i]) numcc++;
    cout << numcc << " " << Count << endl;

}

int main () {
	HNT
    solve();
}

