#include <bits/stdc++.h>
using namespace std;
#define N 1000001

int n, K1, K2, cnt = 0;
int x[N], sum = 0, old_sum = 0;

void TRY(int k){

    if (k>=n) {
        if (!sum || (sum>=K1) && (sum<=K2)) {
            for (int i = 1; i <= n; i++) {
                cout<< x[i] <<" ";
            }
            cout<< endl;
            cnt++;
        }
    }
}

int main (){
    cin>>n>>K1>>K2;
    TRY (1);
    cout << cnt;
    return 0;
}

