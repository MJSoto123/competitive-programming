#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)
#define dbg(a) cerr << (#a) << "\t"; for(auto x : a) cerr << x << " "; cerr << "\n";
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<ll , ll> pii;
typedef vector<pii> vii;

vl Djsktra(vector<vii> g, int n, int src){
    vl d(n + 1, 1e18);
    priority_queue<pii, vii, greater<pii>> q;
    d[src] = 0;
    q.emplace(d[src], src); 

    while(sz(q)){
        auto [dist, u] = q.top(); q.pop();
        if(dist > d[u]) continue;

        for(auto [v, w] : g[u]){
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                q.emplace(d[v], v);
            }
        }
    }
    return d;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vii> g(n + 1);
    vector<vii> g2(n + 1);
    rep(i, 0, m){
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g2[v].emplace_back(u, w);
    }

    vl d1 = Djsktra(g, n, 1);
    vl d2 = Djsktra(g2, n, n);

    // dbg(d1); 
    // dbg(d2);

    ll ans = 5e18;
    for(int u = 1; u <= n; u++){
        for(auto [v, w] : g[u]) ans = min(ans, d1[u] + w / 2 + d2[v]);
    }
    cout << ans << "\n";
}