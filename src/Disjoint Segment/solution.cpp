#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> p;
void input(){
    cin >>n;
    for (int i=1; i<= n; i++){
        int a, b;
        cin >>a>>b;
        p.push_back({a, b});
    }
}

int main(){
    input();
    int last = -1;
    int count = 0;
    sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });
    for (pair<int, int> segment : p){
        if (segment.first > last){
            count++;
            last = segment.second;
        }
    }
    
    cout <<count<<endl;

}