#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);

const int N = 5e3;
#define ll long long

ll n, m, k, q, ans;
ll f[22], g[10];

void solve(){
    g[1] = g[2] = g[3] = g[5] = g[7] = g[8] = f[1] = f[2] = f[3] = f[5] = g[0] = 1;
    g[4] = g[6] = f[4] = f[6] = f[7] = f[8] = 2;
    g[9] = f[9] = 3;
    cin >> q;
    while(q--){
        int c;
        cin >> n >> c;
        if(n % 1000){
            cout << "0\n";
            continue;
        }
        n /= 1000;
        ll N = 0, S = 1;
        ll cmax = 5 * pow(10, c);
        N += (n - cmax) / cmax;
        n -= N * cmax;
        for(int i = 1; i <= c + 1; i++){
            N += f[n % 10];
            S *= g[n % 10];
            n /= 10;
        }
        //if(n > 9){

        //}
        N += n * 2;
        cout << N << " " << S << "\n";
    }
}

int main(){
    HNT
    cout.tie(0);
    cout << fixed << setprecision(10);
    solve();
    return 0;
}
