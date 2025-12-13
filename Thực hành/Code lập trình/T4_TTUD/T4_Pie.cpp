#include<bits/stdc++.h>
using namespace std;

double a[10001];
const double PI = 3.1415926535897932384626433832795;
int n,m;

int Slove(double mid)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum += a[i]*a[i]*PI/mid;
    }
    if(sum >= m+1)return 1;
    else return 0;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0;i < n; i++)
        {
            cin >> a[i];
        }
        double ans=0;
        double mid;
        double l=0;
        double r=1000000000;
        while(r - l >= 1e-7)
        {
            mid = (l+r)/2;
            if(Slove(mid))
            {
                l = mid;
                ans = mid;
            }
            else r = mid;
        }
        printf("%.6f\n",ans);
    }
}
