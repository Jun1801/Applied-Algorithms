#include<bits/stdc++.h>
using namespace std;

int n, C;
int a[10005];
void input(){
    int T;
    cin>>T;
    cin>>n>>C;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
}

bool check(int d){
    // kiểm tra xem có tồn tại dãy con sao cho khoảng cách = d hay ko?
    //Bắt buộc phải có phần tử a[1] để cho khoảng cách nó lớn nhất
    int last = a[1];
    int dem = 1;
    for (int i=2; i<=n; i++){
        if (a[i] - last >= d){
            last = a[i];
            dem++;
        }
        if (dem == C) break;
    }
    return dem >= C;
}

int findD(){
    int l = 1;
    int r = (a[n] - a[1]) / (C-1);
    while (l < r){
        int mid = (l + r + 1)/2;
        if (check(mid)){
            l = mid;
        } else r = mid - 1;
    }
    return l;
}

int main(){
    input();
    sort(a+1, a+n+1);
    cout<<findD();
}