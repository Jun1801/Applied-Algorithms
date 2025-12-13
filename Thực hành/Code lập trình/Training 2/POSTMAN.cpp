b#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e3 + 7;
int n ;
long long k , t = 0;
pair<long long,long long> xm[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> k;
    for(int i = 1 ; i <= n ; i++) cin >> xm[i].first >> xm[i].second;
    sort(xm + 1 , xm + n + 1);

    while(xm[n].first > 0)
    {
        if(xm[n].second < 0)
        {
            if(xm[n-1].first > 0) xm[n-1].second += xm[n].second;
            n-- ;
            continue;
        }
        long long T = xm[n].second / k;
        long long buff = 0;
        if(T * k != xm[n].second)
        {
            ++T;
            buff = k - xm[n].second % k;
        }
        T = T * 2 * xm[n].first;
        t+= T;
        if(xm[n-1].first > 0) {xm[n-1].second -= buff; }
        n--;
    }

    int pos = 1;
    while(xm[pos].first < 0)
    {
        if(xm[pos].second < 0)
        {
            if(xm[pos + 1].first < 0) xm[pos + 1].second += xm[pos].second;
            pos++;
            continue;
        }
        long long T = xm[pos].second / k;
        long long buff = 0;
        if(T * k != xm[pos].second)
        {
            ++T;
            buff = k - xm[pos].second % k;
        }
        T = T * 2 * abs(xm[pos].first);
        t+= T;
        if(xm[pos + 1].first < 0)
        {
            xm[pos + 1].second -=buff;
        }
        pos++;
    }
    cout << t;
    return 0;
}
