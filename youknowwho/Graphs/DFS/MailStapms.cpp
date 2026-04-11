#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    unordered_map<int, vi> g;
    unordered_map<int, int> deg;   
    rep(i, 0, n){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        deg[u]++; deg[v]++;
    }

    int root = -1;
    for(auto [u, c] : deg) if(c == 1) root = u;

    vi path;
    function<void(int, int)> go = [&](int u, int p = -1){
        path.emplace_back(u);
        for(auto v : g[u]){
            if(v == p) continue;
            go(v, u);
        }
    };
    go(root, -1);

    for(auto x : path) cout << x << " "; cout << "\n";
}