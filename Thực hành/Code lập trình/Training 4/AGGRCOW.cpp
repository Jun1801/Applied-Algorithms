#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false); cin.tie(0);
#define MAXN 100001
int N, C;
long long x[MAXN];

void solve() {
    sort(x + 1, x + N + 1);
    int low = -1, high = (int) 1e9 + 10;
    while(high - low > 1) {
        int mid = (low + high) / 2;
        int num = 0;
        int last = (int) -1e9;
        for(int i = 1; i <= N; i++) {
            if(x[i] >= last + mid) {
                num++;
                last = x[i];
            }
        }
        if (num >= C) low = mid;
        else high = mid;
    }
    cout << low << endl;
}

int main () {
    HNT;
    int test;
    cin >> test;
    while(test--) {
        cin >> N >> C;
        for(int i = 1; i <= N; i++) {
            cin >> x[i];
        }
        solve();
    }
    return 0;
}

