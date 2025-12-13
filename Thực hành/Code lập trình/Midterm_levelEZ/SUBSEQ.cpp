#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int cnt = 0;
    for(int i = 0;  i < n; i++){

        int val = arr[i];
        if(val <= m) cnt ++;

        int j = i + 1;
        while(j < n && val + arr[j] <= m){
            cnt++;
            val += arr[j];
            j++;
        }
    }
    cout << cnt;


}
