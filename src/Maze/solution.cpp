#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[1005][1005];
int dist[1005][1005];
int s, e;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int,int>> q;

int main(){
    cin>>m>>n>>s>>e;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }

    q.push({s, e});
    dist[s][e] = 0;
    a[s][e] = 1;
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            
            if (x == 0 || y == 0 || x == m+1 || y == n+1){
                cout << dist[cur.first][cur.second] + 1;
                return 0;
            }
            if (a[x][y] == 0){
                q.push({x, y});
                dist[x][y] = dist[cur.first][cur.second] + 1;
                a[x][y] = 1; // Da duyet, ko dc quay lai
            }
        }
    }
    cout << -1;
    return 0;
}