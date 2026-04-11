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
    vvi g(n + 1);

    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vii edges;
    vi dp(n + 1);
    vi disc(n + 1);
    int timer = 1;
    int bridges = 0;
    function<void(int, int)> go = [&](int u, int p){
        disc[u] = timer++;
        for(auto v : g[u]){
            if(v == p) continue;
            if(disc[v]){
                if(disc[u] < disc[v]) continue;
                edges.emplace_back(u, v);
                dp[u]++; dp[v]--;
                continue;
            }
            edges.emplace_back(u, v);
            go(v, u);
            dp[u] += dp[v];
        }
        if(dp[u] == 0 && u != 1) bridges++;
    }; go(1, -1);

    // rep(u, 1, n + 1) cerr << disc[u] << " \n"[u == n];

    if(bridges){ cout << "0\n"; return 0; }
    for(auto [u, v] : edges) cout << u << " " << v << "\n";
}