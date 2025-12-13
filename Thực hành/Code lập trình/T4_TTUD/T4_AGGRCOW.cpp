#include<bits/stdc++.h>
#define NDS ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
void solve() {
    int n, c;
    cin >> n >> c;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int i = 1, j = a[n - 1], ans;
    while(i <= j){
        int mid = (i + j)/2;
        int temp = 1, fi = a[0];
        for(int k = 1; k < n; k++){
            if(a[k] - fi >= mid) {
                temp++;
                fi = a[k];
            }
        }
        if(temp < c) {
            j = mid - 1;
        }
        else {
            ans = mid;
            i = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main(){
    NDS
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
