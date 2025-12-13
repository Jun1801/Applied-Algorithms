#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(auto &i : a)
        cin>>i;
    sort(a,a+n);
    for(auto i : a)
        cout<<i<<" ";
}
