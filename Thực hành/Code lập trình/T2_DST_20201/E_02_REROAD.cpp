#include<bits/stdc++.h>
using namespace std;
int n,ans;
void solve(int a[])
{
    int x,c;
    cin>>x>>c;
    if(x==1) {
        int cnt=1;
        if(a[x]!=a[x+1]) cnt++;
        ans-=cnt;ans++;
        a[x]=c;
        if(a[x]!=a[x+1]) ans++;
        return;
    }
    if(x==n){
        int cnt=1;
        if(a[x]!=a[x-1]) cnt++;
        ans-=cnt;ans++;
        a[x]=c;
        if(a[x]!=a[x-1]) ans++;
        return;
    }
    int cnt=1;
    for(int i=x;i<=x+1;i++) if(a[i]!=a[i-1]) cnt++;
    ans-=cnt;
    ans++;
    a[x]=c;
    for(int i=x;i<=x+1;i++){
        if(a[i]!=a[i-1]) ans++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=1;
    for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) ans++;
    int k;
    cin>>k;
    while(k--){
        solve(a);
        cout<<ans<<endl;
    }
}
