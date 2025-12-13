#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int n, Q;
int x[2*N];
int cur = 0;
int cnt = 0;
bool check[N];

void solution() {
    for(int i = 1; i <= 2*n ; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    cnt++;
}

void TRY(int k){
    for(int v = 1; v <= 2*n; v++){
        if(!check[v]) {
            if (v <= n){
                if (cur < Q){
                    x[k] = v;
                    check[v] = true;
                    cur++;
                    TRY(k+1);
                    check[v] = false;
                    cur--;
                }
            }
            else {
                if (check[v - n]) {
                    x[k] = v;
                    check[v] = true;
                    cur--;
                    if (k == 2*n) solution();
                    TRY(k+1);
                    check[v] = false;
                    cur++;
                }
            }
        }
    }
}

int main(){
    n = 4;
    Q = 1;
    for (int i = 1; i <= n; i++) check[i] = false;
    TRY(1);
    cout<<"Count = " <<cnt;
    return 0;
}
