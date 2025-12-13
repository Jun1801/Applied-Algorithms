#include <bits/stdc++.h>
using namespace std;

#define HNT ios_base::sync_with_stdio(false); cin.tie();
long n,f;
long double pi = 3.14159265358979323846264338327950;
long func(long double num,long double* r){
    long fr = 0; //fr : friend
    if (num == 0)
        return 0;
    for (long i = 0; i < n; i++)
        fr += (long)(r[i]/num);
    if (fr >= f)
        return 1;
    else
        return 0;
}
long double binarysearch(long double r[]) {
    long double init = 0,last = r[n-1], max=0.0;
    while (last - init >= 1e-6) {
        long double mid = (init+last)/2;
        if (func(mid,r)==1){
            init = mid;
        }
        else
            last=mid;
    }
    return init;
}
int main(){
    HNT;
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> f;
        f++;
        long r[n];
        for (long i = 0; i < n; i++){
            cin >> r[i];
        }
        long double volume[n];
        sort(r,r+n);
        for (long i = 0; i < n; i++){
            volume[i] = r[i]*r[i]*pi;
        }
        printf("%.6Lf\n",binarysearch(volume));
    }
    return 0;
}
