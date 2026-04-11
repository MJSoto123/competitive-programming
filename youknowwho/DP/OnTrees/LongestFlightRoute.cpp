#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vvi g(n);
    vi in(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--; v--;
        g[u].emplace_back(v);
        in[v]++;
    }

    // toposort
    queue<int> q;
    rep(i, 0, n) if(in[i] == 0) q.emplace(i);

    vi ord;
    while(sz(q)){
        auto u = q.front(); q.pop();
        ord.emplace_back(u);
        for(auto v : g[u]){
            in[v]--;
            if(in[v] == 0) q.emplace(v);
        }
    }
    
    int inf = 1e7;
    vi dp(n, -inf), best(n, -1);
    dp[0] = 1;

    for(auto u : ord){
        if(dp[u] == -inf) continue;
        for(auto v : g[u]){
            if(dp[u] + 1 > dp[v]){
                dp[v] = dp[u] + 1;
                best[v] = u;
            }
        }
    }

    if(dp[n - 1] == -inf){ cout << "IMPOSSIBLE\n"; return 0; }
    int u = n - 1;
    vi path;
    while(u != -1){
        path.emplace_back(u);
        u = best[u];
    }

    cout << sz(path) << "\n";
    reverse(all(path));
    for(auto x : path) cout << x + 1 << " "; cout << "\n";
}