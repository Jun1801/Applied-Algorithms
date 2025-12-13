#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);

#define All(a)   (a).begin(), (a).end()
#define Sz(a)    int((a).size())
#define pb push_back
#define ll long long
const int N = 50;

ll n, m, k, q, ans;

vector<int> adj[N];
int visit[N];
map<vector<int>, int> mp;
int x[N];

void dfs(int u, int p){
    visit[u] = 1;
    x[p] = u;
    for(int v: adj[u]){
        if(!visit[v]){
            if(p < k) dfs(v, p + 1);
        } else{
            if(p == k && v == x[1]){
                for(int r = 1; r <= k; r++){
                    vector<int> ans(k);
                    for(int i = r; i <= k; i++){
                        ans[i - r] = x[i];
                    }
                    for(int i = 1; i < r; i++){
                        ans[k - r + i] = x[i];
                    }
                    mp[ans] = 1;
                    reverse(All(ans));
                    mp[ans] = 1;
                }
            }
        }
    }
    visit[u] = 0;
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i = 1; i <= n; i++){
        dfs(i, 1);
    }
    cout << Sz(mp) / 2 / k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);
    solve();
}
