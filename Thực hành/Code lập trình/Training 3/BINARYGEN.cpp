#include<bits/stdc++.h>
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);
using namespace std;


int main() {
    HNT;
    int n, m = -1;
    cin >> n;
    string s;
    cin >> s;
    for(int i = n - 1; i >= 0; i--) {
        if (s[i] == '0'){
            m = i;
            break;
        }
    }
    if(m == -1) cout << m;
    else {
        for(int i = 0; i < m; i++) {
            cout<<s[i];
        }
        cout<< '1';
        for(int i = n - 1; i > m; i--) {
            cout<<'0';
        }
    }
    return 0;
}
