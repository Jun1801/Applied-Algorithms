#include<bits/stdc++.h>
#define MAX 30
using namespace std;
int n, K, Q;
int d[MAX];
int Y[MAX];
int X[MAX];
int seg;
int load[MAX];
bool visited[MAX];
int ans;

void input(){
	cin>>n>>K>>Q;
	for(int i=1; i<=n; i++) cin>>d[i];
}
bool checkX(int v, int k){
	if(v>0){
		if(visited[v]) return false;
		if(load[k]+d[v]>Q) return false;
	}
	return true;
}
void solution(){
	ans++;
	return;
	for(int k=1; k<=K; k++){
		cout<<"0";
		int u=Y[k];
		while(u>0){
			cout<<"-"<<u;
			u=X[u];
		}
	}
}
void tryX(int s, int k){
	for(int v=0; v<=n; v++){
		if(checkX(v,k)){
		X[s]=v;
		visited[v]=true; seg++; load[k]+=d[v];
			if(v==0){
				if(k==K){
					if(seg==n+K) solution();	
			}else{
				tryX(Y[k+1],k+1);
			}
			}else {
				tryX(v,k);
			}
			visited[v]=false; seg--; load[k]-=d[v];
		}
	}
}
bool checkY(int v, int k){
	if(visited[v]) return false;
	if(load[v]>Q) return false;
	return true;
}
void tryY(int k){
	for(int v=Y[k-1]+1; v<=n; v++){
		if(checkY(v,k)){
			Y[k]=v; visited[v]=true; seg++;load[k]+=d[v];
			if(k==K){
				tryX(Y[1],1);
			}else {
				tryY(k+1);
			}
			visited[v]=false; seg--;load[k]-=d[v];
		}
	}
}
 
 void solve(){
 	ans =0;
 	Y[0]=0;
 	seg=0;
 	for(int k=1; k<=K; k++)
 		load[k]=0;
 		tryY(1);
 	cout<<ans;
 }
int main(){
	input();
	solve();
}
