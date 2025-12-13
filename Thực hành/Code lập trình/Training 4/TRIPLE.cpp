#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false); cin.tie(0);
#define MAXN 10001

int n, k;
int x[5001];

void input(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
}

int binarysearch(int left, int right, int value){
     if(left > right) return 0;
     if(left == right){
        if(x[left] == value) return 1;
        else return 0;
     }
     else{
         int mid = (left + right) / 2;
         if(x[mid] == value) return 1 +
            binarysearch(left, mid -1, value) + binarysearch(mid +1, right, value);
         if(x[mid] > value) return binarysearch(left, mid -1, value);
         else return binarysearch(mid +1, right, value);
     }

}

int main(){
    HNT;
    input();
    int cnt = 0;
    sort(x+1, x+n+1);
    int ni = n - 1;
    int nj = n;
    for(int i = 1; i < ni; i++){
        for(int j = i+1; j < nj; j++){
            cnt += binarysearch(j+1, n, k-x[i] - x[j]);
        }
    }
    cout << cnt;
}
