#include<bits/stdc++.h>
using namespace std;
int n, K1, K2;
int P[10005], Q[10005];
int main(){
    memset(P, 0, sizeof(P));
    memset(Q, 0, sizeof(Q));
    cin>>n>>K1>>K2;
    Q[1] = 1;
    Q[0] = 1;
    P[1] = 1;
    P[K1] = 1;
    // 1, 2, ..., K1; nếu K1: work => 1,2,..., K1: work
    for (int i=K1+1; i<=n; i++){
        Q[i] = P[i-1];
        for (int j=K1; j<=K2 && i-j >= 0; j++){
            P[i] += Q[i-j];
        }
    }
    int res = 0;
    res = P[n] + Q[n];
    cout<<res<<endl;
}