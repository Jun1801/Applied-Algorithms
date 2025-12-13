#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false); cin.tie(0);
#define Sz(a)           int((a).size())
#define ll              long long
#define ull             unsigned ll

const int N = 1e5 + 10;
int n, m, k, nex[N];

int Kmp(string s, string p){
    int j = 0;
    int res = 0;
    for(int i = 0; i < Sz(s); i++){
        while(j > 0 && s[i] != p[j]) j = nex[j - 1];
        if(s[i] == p[j]) j++;
        if(j == m) {
            res++;
            j = nex[j - 1];
        }
    }
    return res;
}

void Solve(){
    int q = 0;
    while(cin >> n){
        q++;
        string t = "0", s = "1", p, v;
        cin >> p;
        m = Sz(p);
        for(int i = 2; i <= n; i++){
            v = s;
            s = s + t;
            t = v;
            if(Sz(t) >= 2 * m) {
                k = i + 1;
                break;
            }
        }
        int j = 0;
        for(int i = 1; i < m; i++){
            while(j > 0 && p[i] != p[j]) j = nex[j - 1];
            if(p[i] == p[j]) j++;
            nex[i] = j;
        }
        ull res1 = 0, res2 = 0, res3 = 0;
        res1 = Kmp(s, p);
        res2 = Kmp(t, p);
        res3 = Kmp(s + t, p) - res1 - res2;
        for(int i = k; i <= n; i++){
            ll res = res1;
            res1 = res1 + res2 + res3;
            res2 = res;
        }
        cout << "Case " << q << ": " << res1 << "\n";

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(2);
    Solve();
}
