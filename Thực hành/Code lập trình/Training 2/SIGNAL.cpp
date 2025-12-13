#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,b;
    cin>> n >> b;

    int a[n];
    int cnt = 0;
    for(int i = 0;i < n; i++) cin>>a[i];

    int f[n];
    f[n-1] = a[n-1];

    for(int i = n-2;i >= 0;i--){
        f[i] = max(a[i],f[i+1]);
    }

    int rs = 0;
    int maxs = 0;

    for(int i = 1;i < n-1; i++){
        maxs = max(maxs,a[i-1]);
        if((maxs - a[i] >= b) && (f[i+1] - a[i] >= b)){
            rs = max(rs,maxs + f[i+1] - 2*a[i]);
            cnt++;
        }
    }

    if(cnt) cout<< rs <<endl;
    else cout<< -1 <<endl;
}
