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
    vi deg(n + 1);
    rep(i, 1, n){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        deg[u]++; deg[v]++;
    }

    int leaves = 0;
    rep(i, 2, n + 1) if(deg[i] == 1) leaves++;
    vi need(leaves);
    rep(i, 0, leaves) cin >> need[i];
    vi ord(n + 1, 1e9);
    rep(i, 0, leaves) ord[need[i]] = i;

    function<void(int, int)> getorder = [&](int u, int p = -1){
        for(auto v : g[u]){
            if(v == p) continue;
            getorder(v, u);
            ord[u] = min(ord[u], ord[v]);
        }
    }; getorder(1, -1);

    vi path;
    function<void(int, int)> getpath = [&](int u, int p = -1){
        vi children;
        for(auto v : g[u]) if(v != p) children.emplace_back(v);
        sort(all(children), [&](int i, int j){
            return ord[i] < ord[j];
        });

        path.emplace_back(u);
        for(auto v :children){
            getpath(v, u);
            path.emplace_back(u);
        }
    }; getpath(1, -1);

    int idx = 0;
    rep(i, 0, sz(path)){
        if(path[i] == need[idx]) idx++;
        if(idx == sz(need)) break;
    }
    if(idx != sz(need)){ cout << "-1\n"; return 0; }
    for(auto x : path) cout << x << " "; cout << "\n";
}