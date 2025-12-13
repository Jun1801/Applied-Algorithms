#include <iostream>
#include <string>

using namespace std;

char a[1000][1000];

int islands(int x, int y, int n, int m) {
    a[x][y] = '0';
    int c = 1;
    if (a[x][y-1] == '1' && y > 0) {
        c += islands(x, y-1, n, m);
    }
    if (a[x][y+1] == '1' && y < m-1) {
        c += islands(x, y+1, n, m);
    }
    if (a[x-1][y] == '1' && x > 0) {
        c += islands(x-1, y, n, m);
    }
    if (a[x+1][y] == '1' && x < n-1) {
        c += islands(x+1, y, n, m);
    }
    return c;
}

main() {
    int n, m, i, j, d = 0, c, max = 0;

    cin >> n >> m;

    for (i = 0; i < n; i++)
    	for (j = 0; j < m; j++)
        	cin >> a[i][j];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == '1'){
            	d++;
                c = islands(i, j, n, m);
                if (max < c) max = c;
            }
        }
	}
    cout << d << endl;
    cout << max;
}

