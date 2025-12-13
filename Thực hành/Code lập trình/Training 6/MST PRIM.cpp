#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false); cin.tie();

typedef pair<int,int> pi;
typedef vector<int> vi;
const int Max = 100001, oo=INT_MAX;

int n,m,d[Max];
vi a[Max],b[Max];

long long prim(int u) {
    long long ans = 0;
    priority_queue<pi> qu;
    for(int i = 1;i <= n; i++)
        d[i] = oo;
    qu.push(pi(0, u));
    d[u] = 0;
    while(!qu.empty()){
        pi top = qu.top();
        qu.pop();
        int u = top.second, du = -top.first;
        if(du != d[u]) continue;
        ans += d[u];
        d[u] = 0;
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i];
            if(d[v] > b[u][i]){
                d[v] = b[u][i];
                qu.push(pi(-d[v],v));
            }
        }
    }
    return ans;
}

int main(){
    HNT
    cin>> n >> m;
    for(int i = 0;i < m; i++) {
        int x, y, z;
        cin>> x>> y>> z;
        a[x].push_back(y);
        b[x].push_back(z);
        a[y].push_back(x);
        b[y].push_back(z);
    }
    cout<<prim(1)<<endl;
}
