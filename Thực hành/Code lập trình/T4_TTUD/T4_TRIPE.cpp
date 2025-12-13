#include<bits/stdc++.h>
using namespace std;
const int Max = 100001;
int n, k, x, ans = 0;
int a[Max];
int b[Max];
bool c[Max];

int binary(int d, int c, int x, int a[]){
    int tg = (d + c)/2;
    if(d > c) return 0;
    if(a[tg] == x) return 1 + binary(d, tg - 1, x, a) + binary(tg + 1, c, x, a);
    else {
        if(a[tg] < x) return binary(tg + 1, c, x, a);
        else return binary(d, tg - 1, x, a);
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            ans += binary(j + 1, n - 1, k - a[i] - a[j], a);
        }
    }
    cout << ans << "\n";
}
