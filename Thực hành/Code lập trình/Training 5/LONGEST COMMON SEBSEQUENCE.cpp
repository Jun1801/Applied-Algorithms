#include <bits/stdc++.h>
using namespace std;
#define HNT  ios_base::sync_with_stdio(false);    cin.tie(0);

int LCS(int X[], int Y[], int m, int n) {

    int curr[n + 1], prev;

    for (int i = 0; i <= m; i++){

        prev = curr[0];

        for (int j = 0; j <= n; j++){
            int backup = curr[j];

            if (i == 0 || j == 0)
                curr[j] = 0;
            else{
                if (X[i - 1] == Y[j - 1])
                    curr[j] = prev + 1;

                else
                    curr[j] = max(curr[j], curr[j - 1]);
            }
            prev = backup;
        }
    }
    return curr[n];
}

int main() {
    HNT;
    int n, m;
    cin >> n >> m;
    int x[n], y[m];

    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < m; i++) cin >> y[i];
    cout << LCS (x,y,n,m);
    return 0;
}
