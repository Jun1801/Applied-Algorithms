#include<bits/stdc++.h>
using namespace std;

int main (){
    const long c = 1000000007;
    unsigned long long a,b,d;
    cin>>a>>b;
    a = a%c;
    b = b%c;
    d = (a + b)%c;
    cout<<d;
}
