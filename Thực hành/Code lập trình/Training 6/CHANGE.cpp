#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);

int main() {
    HNT
    int n;
    cin >> n;
    n = 1000 - n;
    int a[6] = {1, 5, 10, 50, 100, 500};
    int res = 0;
    for (int i = 5; i >= 0; i--) {
        res += n / a[i];
        n %= a[i];
    }
    cout << res << endl;
    return 0;
}
