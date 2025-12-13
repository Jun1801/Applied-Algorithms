#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 5;

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }

    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        if (n > 0)
            range_min[0] = values;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query_value(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};

void solve(){
   int n, k;
   cin >> n;
   vector<int> arr(n);
   for(int i = 0; i < n; i++)
      cin >> arr[i];
   RMQ<int> rmq(arr);

   ll res = 0;
   cin >> k;
   for(int i = 0; i < k; i++){
      int l, r;
      cin >> l >> r;
      res += rmq.query_value(l, r + 1);
   }
   cout << res << "\n";

}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cout << fixed << setprecision(10);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w", stdout);
   int query = 1;
   // cin >> query;
   //int start = 1000 * clock() / CLOCKS_PER_SEC;
   while(query--) solve();
   //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC  - start << "ms\n";
}
