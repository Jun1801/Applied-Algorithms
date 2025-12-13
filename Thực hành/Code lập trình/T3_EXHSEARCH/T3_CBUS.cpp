#include<bits/stdc++.h>
#define NDS ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int n, Q, cnt, ftop = INT_MAX,f = 0, rmin = INT_MAX;
bool b[100];
int a[100];
int road[100][100];

bool check(int k, int v) {
    if(b[v] == false) return false;
//    if(v <= n && b[v + n] == false) return false;
    if(v > n && cnt == 0) return false;
    if(v <= n && cnt >= Q) return false;
    if(v > n && b[v-n]) return false;
    return true;

}

void Try(int k) {
	for(int v = 1; v <= 2*n; v++)
		if(check(k, v))
		{
			a[k] = v;
			f += road[a[k - 1]][a[k]];
			b[v] = false;
			if(v <= n) cnt++;
			else cnt--;
			if(k == 2*n) {
                    //cout << f << "\n" ;
                    ftop = min(ftop, f + road[a[k]][0]);

			}
			else
                if(f + (2*n - k+1) * rmin < ftop) Try(k + 1);
			f -= road[a[k-1]][a[k]];
			if(v <= n) cnt--;
			else cnt++;
			b[v] = true;
		}
}

int main() {

    NDS
	cin >> n >> Q;
	for(int i = 0; i <= 2*n; i++)
        for(int j = 0; j <= 2*n; j++)
            {
                cin >> road[i][j];
                if(i != j && road[i][j] < rmin) rmin = road[i][j];
            }
    a[0] = 0;
	cnt = 0;
	memset(b,true,sizeof(b));
	Try(1);
	cout << ftop ;
}
