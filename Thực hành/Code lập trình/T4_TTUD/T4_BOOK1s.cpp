#include <bits/stdc++.h>
#define NDS ios_base::sync_with_stdio(false);cin.tie(0);
#define ull unsigned long long
using namespace std;
int m , k;
bool check( vector<int> &v , ull mid){
    int  n = v.size() , i = 0 , cnt = 1;
    ull count = 0;
    while(i < n)
    {
        if((long long)v[i] > mid)
            return false;
        if(count + (long long )v[i] > mid){
            cnt++;
            count = 0;
        }
        if(count <= mid){
            count += (long long)v[i];
            i++;
        }
    }
    if(cnt <= k)
        return true;
    return false;
}
void print(int pos , int k ,vector<int> &v , ull mid){
    ull count = 0;
    int pos_till = -1;
    for(int i = pos ; i>= 0 ; i--){
        if(count + v[i] > mid || i == k-2){
            print(i , k-1  , v , mid);
            pos_till = i;
            break;
        }
        count += v[i];
    }
    if(pos_till >= 0)
        cout << "/ ";
    for(int i = pos_till +1 ; i<= pos ; i++)
        cout << v[i] << " ";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> k;
        vector<int> v(m);
        for(int i = 0 ; i < m ; i ++){
            cin >> v[i];
        }
        v.push_back(0);
        ull low = 1 , high = LLONG_MAX , mid , ans = LLONG_MAX;
        while(low < high){
            mid = (low + high)>>1;
            if(check( v , mid)){
                ans = min(ans , mid);
                high = mid;
            } else
                low = mid+1;
        }
        print(v.size() - 2 , k , v , ans);
        cout << "\n";
    }
    return 0;
}
