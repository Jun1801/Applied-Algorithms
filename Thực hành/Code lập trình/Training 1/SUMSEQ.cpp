#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(auto &i : a) cin>>i;
    int ans=0;
    for(auto &i : a) {ans += i;ans %= mod;}
    cout << ans << "\n";
}
