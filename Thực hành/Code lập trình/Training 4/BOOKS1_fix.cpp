#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false); cin.tie(0);

#define MAXN 100001
long long a[MAXN];
long long K, P;

bool check(long long max_val) {
    vector<int> pos;
    long long sum = 0;
    for (int i = K; i >= 1; i--) {
        if(sum + a[i] <= max_val) {
            sum += a[i];
        }
        else {
            sum = a[i];
            if(a[i] > max_val) {
                return false;
            }
            pos.push_back(i);
        }
    }
    if(pos.size() >= P) {
        return false;
    }
    // In kết quả
    int m = pos.size();
    for(int i = 0; i < m; i++) {
        cout << a[pos[i]];
    }
    cout << "/ ";
    return true;
}
int main () {
    HNT;
    int test;
    cin >> test;
    while(test--) {
        cin >> K >> P;
        for(int i = 1; i <= K; i++) {
            cin >> a[i];
        }
        if (check(100)) cout << endl;
    }
    return 0;
}
