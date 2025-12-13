#include<bits/stdc++.h>
using namespace std;

int main (){
    long n;
    cin >> n;
    long long a[n];
    long long s[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    s[0] = a[0];
    long long max = s[0];
    for (int i = 1; i < n; i++) {
        if(s[i-1] > 0) s[i] = s[i-1] + a[i];
        else s[i] = a[i];
        max = max > s[i] ? max : s[i];
    }
    cout << max;
}
