#include<bits/stdc++.h>
#define MAX 30
using namespace std;
int n, K, Q;
int c[MAX][MAX];
int d[MAX];
int Y[MAX];
int X[MAX];
int seg;
int load[MAX];
bool visited[MAX];
int s = 0;
int ans;

void input(){
	cin>>n>>K>>Q;
	for(int i=1; i<=n; i++) cin>>d[i];
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			cin >> c[i][j];
}
bool checkX(int v, int k){
	if(v>0){
		if(visited[v]) return false;
		if(load[k]+d[v]>Q) return false;
	}
	return true;
}
void solution(){
	s=0;
//	return;
	for(int k=1; k<=K; k++){
//		cout<<"0";
		int u=Y[k];
		s+=c[0][u];
		while(u>0){
//			cout<<"-"<<u;
			s+=c[u][X[u]];
			u=X[u];
		}
	}
	ans=min(ans,s);
}
void tryX(int x, int k){
	for(int v=0; v<=n; v++){
		if(checkX(v,k)){
			X[x]=v;
			visited[v]=true; 
			seg++;
//			s+=c[X[x-1]][v]; 
			load[k]+=d[v];
			if(v==0){
				if(k==K){
					if(seg==n+K) solution();	
				}else{
					tryX(Y[k+1],k+1);
				}
			}else {
				tryX(v,k);
			}
			visited[v]=false; 
			seg--; 
			load[k]-=d[v];
//			s-=c[X[x-1]][v]; 
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
			Y[k]=v; 
			visited[v]=true; 
			seg++;
//			s+=c[0][v];
			load[k]+=d[v];
			if(k==K){
				tryX(Y[1],1);
			}else {
				tryY(k+1);
			}
			visited[v]=false; 
			seg--;
//			s-=c[0][v]; 
			load[k]-=d[v];
		}
	}
}
 
void solve(){
 	ans = INT_MAX;
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
