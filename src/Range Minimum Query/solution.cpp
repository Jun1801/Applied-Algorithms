#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+5;
int n, m;
int a[maxN];
vector<pair<int, int>> pairs;
int M[maxN][30];
void buildM(){

    // M[i][k] = min_idx (a_i, a_i+1, a_i+2, ..., a_{i+2^k -1})
    for (int i=0; i<n; i++){
        M[i][0] = i;
    }

    for (int j=1; (1<<j) <= n; j++){
        for (int i=0; i + (1<<j) <= n; i++){
            // Tìm min index
            // M[i][j-1] : min_index (a[i], a[i+1], ..., a[i+2^{j-1} -1])
            // M[i + (1<<(j-1))][j-1]: min_index (a[i + 2^{j-1}], a[i+2^{j-1} + 1], ..., a[i+2^{j-1} + 2^{j-1} - 1])
            if (a[M[i][j-1]] < a[M[i+(1<<(j-1))][j-1]]){
                M[i][j] = M[i][j-1]; 
            }
            else M[i][j] = M[i+(1<<(j-1))][j-1];
        }
    }
}

int rmq(int i, int j){
    int k = log2(j-i+1);
    return min(a[M[i][k]], a[M[j-(1<<k)+1][k]]);
}

int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    cin>>m;
    for (int i=0; i<m; i++){
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        pairs.push_back(tmp);
    }
    buildM();
    long long res = 0;
    for (pair<int, int> p : pairs){
        res += rmq(p.first, p.second);
    }
    cout<<res<<endl;


}

