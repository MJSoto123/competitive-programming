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

    int n; cin >> n;
    vvi g(n + 1);
    set<pii> edges;
    map<pii, int> cost;
    rep(i, 0, n){
        int u, v, c; cin >> u >> v >> c;
        edges.emplace(u, v);
        cost[{u, v}] = c;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    vi vis(n + 1);
    function<int(int)> go = [&](int u){
        int ret = 0;
        for(auto v : g[u]){
            if(vis[v]) continue;
            if(!edges.count({u, v})) ret += cost[{v, u}];
            vis[v] = 1;
            ret += go(v);
        }
        return ret;
    };

    int ans = 1e9;
    int u = g[1][0], v = g[1][1];
    rep(i, 0, 2){
        vis.assign(n + 1, 0);
        vis[1] = vis[v] = 1;
        int anshere = go(v);
        // u --> 1 --> v
        if(!edges.count({u, 1})) anshere += cost[{1, u}];
        if(!edges.count({1, v})) anshere += cost[{v, 1}];

        ans = min(ans, anshere);
        swap(u, v);
    }
    cout << ans << "\n";
}