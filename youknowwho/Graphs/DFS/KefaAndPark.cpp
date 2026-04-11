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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int n, k; cin >> n >> k;
    vi cat(n);
    rep(i, 0, n) cin >> cat[i];

    vvi g(n);
    vi deg(n);
    rep(i, 1, n){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        deg[u]++; deg[v]++;
    }
    
    vi vis(n);
    int ans = 0;
    function<void(int, int)> go = [&](int u, int c){
        if(cat[u]) c++;
        if(c > k) return;
        if(!cat[u]) c = 0;
        
        if(deg[u] == 1 && u != 0) ans++;
        for(auto v : g[u]){  
            if(vis[v]) continue;
            vis[v] = 1;
            go(v, c);
        }
    };
    
    vis[0] = 1;
    go(0, 0);
    cout << ans << "\n";
}