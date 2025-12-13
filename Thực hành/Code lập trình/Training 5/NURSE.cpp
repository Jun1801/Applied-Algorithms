#include<bits/stdc++.h>
using namespace std;
#define HNT  ios_base::sync_with_stdio(false);    cin.tie(0);

long long N, K1, K2, cnt = 0;

void TRY(int v){
	for(int k = K1; k <= K2; k++){
		v = v + k;
		if(v == N || v == (N-1)){
			cnt++;
		}
		else{
			if(v + K1 <= N) TRY(v+1);
		}
		v = v - k;
	}
}

int main(){
    HNT;
	cin >> N >> K1 >> K2;
	TRY(0);
	TRY(1);
	cout << cnt;
}
