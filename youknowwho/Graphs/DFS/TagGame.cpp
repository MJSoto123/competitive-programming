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

    int n, x; cin >> n >> x;
    vvi g(n + 1);

    rep(i, 1, n){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi alice(n + 1), bob(n + 1);
    vi d(n + 1);
    function<void(int)> go = [&](int u){
        for(auto v : g[u]){
            if(d[v] != -1) continue;
            d[v] = d[u] + 1;
            go(v);
        }
    };

    d.assign(n + 1, -1); d[1] = 0;
    go(1); alice = d;

    d.assign(n + 1, -1); d[x] = 0;
    go(x); bob = d;
    
    int ans = 0;
    rep(i, 1, n + 1){
        if(bob[i] < alice[i]) ans = max(ans, alice[i]);
    }

    cout << ans * 2 << "\n";
}