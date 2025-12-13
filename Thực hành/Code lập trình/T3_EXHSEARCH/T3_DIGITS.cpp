#include<bits/stdc++.h>
using namespace std;
int n;
int a[8];
int cnt = 0;
bool b[10];

bool check(int i, int k) {
	if(b[i]) return true;
	return false;
}

void Try(int k) {
	for(int i = 1; i <= 9; i++)
	if(check(i,k))
	{
		a[k] = i;
		b[i] = false;
		if(k == 7) {
			if((a[1]*100 + a[2] *10 + a[3]) - (a[4]*100 + 62) + (a[5]*1000 + a[6]*100 + a[7]*10 + a[3]) == n) {
				cnt++;
			//	for(int j = 1; j <= 7; j++) cout << a[j] << " ";
			//	cout << "\n";
			}
		}
		else Try(k + 1);
		b[i] = true;
	}
}


int main() {
	cin >> n;
	for(int i = 0; i < 10; i++) b[i] = true;
	Try(1);
	cout << cnt << "\n";
}
