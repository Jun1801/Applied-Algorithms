#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);

int main(){
    HNT
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if(a[x] == 0 && a[y] == 0) {a[x] = 1; a[y] = 2; continue;}
        if(a[x] == 1 && a[y] == 0) {a[y] = 2; continue;}
        if(a[x] == 0 && a[y] == 1) {a[x] = 2; continue;}
        if(a[x] == 2 && a[y] == 0) {a[y] = 1; continue;}
        if(a[x] == 0 && a[y] == 2) {a[x] = 1; continue;}
        if(a[x] == a[y]) {
            cnt++;
            break;
        }
    }
    if(cnt) cout << 0 << "\n";
    else cout << 1 << "\n";
    return 0;
}
