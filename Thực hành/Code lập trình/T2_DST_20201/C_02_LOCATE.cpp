#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > V1, V2;
int L, C, m, x[2001][2001], k=0, kq[100001];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> m;
	while(m--)
    {
		int ans = 0;
		V1.clear();
		V2.clear();
		cin >> L >> C;
		for(int i=0; i<=2000; i++){
			for(int j=0; j<=2000; j++){
				x[i][j] = 0;
			}
		}
		for(int i=0; i<L; i++){
			for(int j = 0; j<C; j++){
				int a;
				cin >> a;
				if(a == 1){
					V1.push_back({i, j});
				}
			}
		}
		for(int i=0; i<L; i++){
			for(int j = 0; j<C; j++){
				int b;
				cin >> b;
				if(b == 1){
					V2.push_back({i, j});
				}
			}
		}
		for(int i=0; i<V1.size(); i++){
			for(int j=0; j<V2.size(); j++){
				x[V1[i].first-V2[j].first+1000][V1[i].second-V2[j].second+1000] ++;
				ans = max(ans, x[V1[i].first-V2[j].first+1000][V1[i].second-V2[j].second+1000]);
			}
		}
		cout<<ans<<endl;
	}

}
