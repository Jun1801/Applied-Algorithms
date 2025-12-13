#include <bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);

#define maxn 100002
#define maxw 105
int N;
vector<int> a[maxn];
vector<int> c[maxn];
int d[maxn], p[maxn];

void bfs(int u){
    queue<int> Q;
    d[u] = 0;
    Q.push(u);
    while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        int a_leng = a[v].size();
        for(int i = 0; i < a_leng; i++){
            int x = a[v][i];
            if(p[x] > -1){
                continue;
            }
            Q.push(x);
            int w = c[v][i];
            d[x] = d[v] + w;
            p[x] = v;
        }
    }
}

int find_max(){
    int max_d = -1;
    int u = -1;
    for(int v = 1; v <= N; v++){
        if(max_d < d[v]){
            max_d = d[v];
            u = v;
        }
    }
    return u;
}

void init(){
    for(int i = 1; i <= N; i++){
        d[i] = -1;
        p[i] = -1;
    }
}

void solve(){
    cin >> N;
    for(int i = 1; i <= N-1; i++){
        int x, y , w;
        cin >> x >> y >> w;
        a[x].push_back(y);
        c[x].push_back(w);
        a[y].push_back(x);
        c[y].push_back(w);
    }
    init();
    bfs(1);
    int u = find_max();
    /*for(int i = 1; i <= N; i++)
        cout << d[i] << " ";
    */
    init();
    bfs(u);
    cout << d[find_max()];
}

int main(){
    HNT
    solve();
    return 0;
}

