#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+5;
int n, m;
int a[MAX][MAX];

int histogram[MAX][MAX]; // h[i][j]: chiều cao của hình chữ nhật thứ j trong histogram
// được tạo bởi từ tầng 1 -> tầng i

void input(){
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin>>a[i][j];
            if (a[i][j] == 0) histogram[i][j] = 0;
            else histogram[i][j] = histogram[i-1][j] + 1;
        }
    }
}



int maxArea(int i){
    // Tìm maxArea cho histgram các hình chữ nhật của tầng i -> hàng 1
    stack<pair<int, int>> s;
    int maxSubArea = 0;
    for (int j = 1; j<=m ; j++){
        int h = histogram[i][j];
        int start = j;
        while (!s.empty() && s.top().second > h){
            int idx = s.top().first;
            int height = s.top().second;
            s.pop();
            maxSubArea = max(maxSubArea, height*(j - idx));
            start = idx;
        }
        s.push({start, h});
        
    }
    while(!s.empty()){
        int idx = s.top().first;
        int h = s.top().second;
        s.pop();
        maxSubArea = max(maxSubArea, h*(m - idx + 1));
    }
    return maxSubArea;
}


int main(){
    memset(histogram, 0, sizeof(histogram));
    input();
    
    int res = 0;
    for (int i=1; i<= n; i++){
        res = max(res, maxArea(i)); 
    }
    cout<<res<<endl;
}