#include <iostream>
#include <stack>
using namespace std;

long long maxs(long long *a, int n){
	stack<int> S;
	long long i = 0;
	long long ftop = 0;
	long long fk = 0;
	while(i < n){
            if(S.empty()||a[i]>=a[S.top()])
            {
                S.push(i);
                i++;
            }
            else
            {
                int t=S.top();
                S.pop();
                if(S.empty())
                    fk=a[t]*i;
                else
                    fk=a[t]*(i-1-S.top());
                ftop=max(ftop,fk);
            }
	}
    while(!S.empty())
    {
        int top=S.top();
        S.pop();
        if(S.empty())
            fk=a[top]*i;
        else fk=a[top]*(i-1-S.top());
        ftop=max(fk,ftop);
    }
	return ftop;
}

int main(){
	int n, f=0;
	static long long a[1000001], m[1000001];
	while(true){
	    cin >> n;
		if(n==0) break;
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		cout<<maxs(a, n)<<endl;
	}
}
