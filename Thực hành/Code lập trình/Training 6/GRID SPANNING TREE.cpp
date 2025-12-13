#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    std::vector<long long> f(n + 1, 0);
    f[1] = 1;
    for(int i = 2; i <= n; i++){
        f[i] = (4 * f[i - 1] - f[i - 2] + MOD) % MOD;
    }
    cout << f[n] << "\n";
    return 0;
}
