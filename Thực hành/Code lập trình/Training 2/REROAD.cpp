#include<bits/stdc++.h>
using namespace std;
int n,rs;

void solve(int t[])
{
    int x,c;
    cin>>x>>c;
    if(x==1) {
        int cnt=1;
        if(t[x]!=t[x+1]) cnt++;
        rs-=cnt;
        rs++;
        t[x]=c;
        if(t[x]!=t[x+1]) rs++;
        return;
    }

    if(x==n){
        int cnt=1;
        if(t[x]!=t[x-1]) cnt++;
        rs-=cnt;
        rs++;
        t[x]=c;
        if(t[x]!=t[x-1]) rs++;
        return;
    }

    int cnt=1;
    for(int i=x;i<=x+1;i++) if(t[i]!=t[i-1]) cnt++;
    rs-=cnt;
    rs++;
    t[x]=c;

    for(int i=x;i<=x+1;i++){
        if(t[i]!=t[i-1]) rs++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    int t[n+1];
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }

    rs=1;
    for(int i=2;i<=n;i++) if(t[i]!=t[i-1]) rs++;
    int q;
    cin>>q;
    while(q--){
        solve(t);
        cout<<rs<<endl;
    }
}
