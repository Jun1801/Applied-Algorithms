#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int cnt=0;
    queue<pair<int,int>> Q;
    if(c>a&&c>b || c% __gcd(a,b)!=0) cout<<-1<<endl;
    else
    {
        if(a==c || b==c)
        {
            cout<<1<<endl;
            return;
        }
        if(a>b) swap(a,b);
        map<pair<int,int>,int> d;
        pair<int,int> p = pair<int,int>(a,0);
        pair<int,int> p1= pair<int,int>(b,0);
        d[p]=1;
        d[p1]=1;
        Q.push(p);
        Q.push(p1);
        while(!Q.empty())
        {
           pair<int,int> pi = Q.front();
           Q.pop();
           int x=pi.first;
           int y=pi.second;
           cnt++;
           if(cnt%2)
           {
               if(x==0) {x=a;}
               else
               {
                   if(y==b) {y=0;}
                   else
                   {
                       if(x>0&&y<b)
                       {
                            if(x>b-y) {x-=b-y;y=b;}
                            else {y+=x;x=0;}
                       }
                   }
               }
               if(x==c||y==c) {cout<<d[pi]+1<<endl ;return;}
               else
               {
                   pair<int,int>p2= pair<int,int>(x,y);
                   Q.push(p2);
                   d[p2]=d[pi]+1;
               }
            }
            else
            {
               if(x==0) {x=b;}
               else
               {
                   if(y==a) {y=0;}
                   else
                   {
                       if(x>0&&y<a)
                       {
                            if(x>a-y) {x-=a-y;y=a;}
                            else {y+=x;x=0;}
                       }
                   }
               }
               if(x==c||y==c) {cout<<d[pi]+1<<endl ;return;}
               else
               {
                   pair<int,int>p2= pair<int,int>(x,y);
                   Q.push(p2);
                   d[p2]=d[pi]+1;
               }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    solve();

}
