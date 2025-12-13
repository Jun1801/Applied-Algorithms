#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);

int main() {
    HNT
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(rbegin(a), rend(a));
    for (int i = 0; i < n; i++) a[i] += i;
    cout << *max_element(begin(a), end(a)) + 2 << endl;
    return 0;
}
