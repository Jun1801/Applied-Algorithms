#include<bits/stdc++.h>
#define HNT   ios_base::sync_with_stdio(false);   cin.tie(0);
using namespace std;

#define MAXN 20
int a[MAXN],n,count;

void print_sol(){
	/*for(int i = 1; i<=n ;i++)
        cout<<a[i]<<" ";
	cout<<endl;*/
	count++;
}

int UCV(int y, int i ){
	for(int j = 1; j < i; j++){
	    if(a[j] == y) return 0;
        if( fabs(i - j) == fabs (a[j] - y) )return 0;
	}
	return 1;
}

void TRY (int i){
	int y;
	for(y = 1; y <= n; y++) {
        if (UCV(y,i)) {
            a[i] = y;
            if (i == n) print_sol();
            else TRY (i+1);
        }
	}
}

int main () {
    do {
        int x, y;
        cin >> x >> y;
    }while(!x || !y)


	count = 0;
	TRY (1);
	cout<<"Number of solutions: "<<count;
	return 0;
}
