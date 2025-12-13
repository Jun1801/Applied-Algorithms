#include<bits/stdc++.h>
#define HNT   ios_base::sync_with_stdio(false);   cin.tie(0);
using namespace std;

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    k--;

    while (cnt != -1) {
        if(next_permutation(a.begin(), a.end())) {
            if(++cnt == k) {
                for (int i = 0; i < n; i++) {
                    cout << a[i] << " ";
                }
                break;
            }
        }
        else {
            cnt = -1;
            cout<<cnt;
        }
    }
    return 0;
}

