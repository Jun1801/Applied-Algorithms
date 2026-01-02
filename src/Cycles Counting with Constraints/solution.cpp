#include <bits/stdc++.h>
using namespace std;
int n, l;
int x[10005], y[10005];
bool visited[10005];
int r[10005];
int dist = 0;
int dem = 0;
void input(){
    cin>>n;
    for (int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    cin>>l;
}

int distance(int i, int j){
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}


void Try(int k){
    // Tìm giá trị cho r[k]
    for (int v=1; v<=n; v++){
        if (!visited[v]){
            r[k] = v;
            int d = distance(r[k-1], v);
            if (dist + d > l) continue;
            dist += d;
            visited[v] = true;
            if (k==n){
                if (dist + distance(r[n], r[1]) <= l) dem++;
            }
            else Try(k+1);

            dist -= distance(r[k-1], v);
            visited[v]= false;
        }
    }
}

int main(){
    input();
    memset(visited, false, sizeof(visited));
    r[1] = 1;
    visited[1] = true;
    Try(2);
    cout<<dem<<endl;
}