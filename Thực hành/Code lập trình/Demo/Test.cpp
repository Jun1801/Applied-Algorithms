#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

vii a;
int n;

void solve(){
    cin >> n;
    a.resize(n + 1, vi(0));
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);

    }
}
int main (){

}

