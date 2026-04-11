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
    vector<tuple<int, int, int>> ed(m);

    vvi g(n + 1);
    rep(i, 0, m){
        int u, v, w; cin >> u >> v >> w;
        ed[i] = make_tuple(u, v, -w);
        g[u].emplace_back(v);
    }

    ll inf = 5e18;
    vl dist(n + 1, inf); dist[1] = 0;
    auto go = [&](){
        for(auto [u, v, w] : ed) if(dist[u] != inf){
            dist[v] = min(dist[v], dist[u] + w);
        }
    };

    rep(i, 0, n - 1) go();
    vl best = dist;
    go();

    queue<int> q;
    vi vis(n + 1);
    rep(i, 1, n + 1) if(dist[i] < best[i]){
        q.emplace(i);
        vis[i] = 1;
    }

    while(sz(q)){
        auto u = q.front(); q.pop();
        for(auto v : g[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            q.emplace(v);
        }
    }

    if(vis[n]) cout << "-1\n";
    else cout << -dist[n] << "\n";
}