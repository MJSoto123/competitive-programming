#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(int n) {
    vector<vector<int>> a(n);
    map<int, set<int>> mp;
    set<int> b;
    
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        a[i].assign(m, 0);
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mp[a[i][j]].insert(i);
            b.insert(a[i][j]);
        }
    }
    
    vector<int> go;
    for(auto x : b) go.emplace_back(x);
    int mn = go[0];
    
    // k diff => k - 1 ops
    vector<int> dp(n, 1e18);
    int ini = (int)(mp[mn].size());
    for (auto x : mp[mn]) dp[x] = ini - 1;
    
    for (int i = 1; i < (int)(go.size()); i++) {
        int curr = go[i], last = go[i - 1];
        vector<int> now(n, 1e18);

        for (auto x : mp[curr]) {
            for (auto y : mp[last]) {
                int upd = dp[y] + (int)(mp[curr].size()) - 1;
                if (mp[curr].find(y) == mp[curr].end()) upd++;
                
                now[x] = min(now[x], upd);
            }
        }
        dp = now;
    }
    
    int ans = 1e18;
    int mx = go.back();
    for (auto x : mp[mx]) ans = min(ans, dp[x]);

    cout << 2 * ans + 1 - n << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, tt = 1;
    while (cin >> n) {
        cout << "Case " << tt << ": "; 
        solve(n);
        tt++;
    }
    return 0;
}
