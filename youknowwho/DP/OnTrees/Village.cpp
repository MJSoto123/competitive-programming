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
    vvi g(n);

    rep(i, 0, n - 1){
        int u, v; cin >> u >> v; u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi rt(n), par(n);
    function<void(int)> dfs = [&](int u){
        for(auto v : g[u]){
            if(v == par[u]) continue;   
            par[v] = u;
            dfs(v);
            if(!rt[v]) rt[u] = 1;

        }
        if(u == 0 && !rt[u]){
            rt[u] = 1;
            rt[g[u][0]] = 0;
        }
    }; par[0] = -1; dfs(0);

    vi ans(n), a;
    function<void(int)> go = [&](int u){
        a.emplace_back(u);
        for(auto v : g[u]){
            if(v == par[u] || rt[v]) continue;
            go(v);
        }
    };

    int len = 2 * n;
    rep(i, 0, n){
        if(rt[i] == 1){
            len -= 2;
            a.clear();
            go(i);
            rep(j, 0, sz(a)) ans[a[j]] = a[(j + 1) % sz(a)];
        }
    }

    cout << len << "\n";
    rep(i, 0, n) cout << ans[i] + 1 << " "; cout << "\n";
}