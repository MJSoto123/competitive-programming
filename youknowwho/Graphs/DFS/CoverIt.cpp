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

void solve(){
    int n, m; cin >> n >> m;
    vvi g(n + 1);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi vis(n + 1, -1);
    function<void(int)> go = [&](int u){
        for(auto v : g[u]){
            if(vis[v] != -1) continue;
            vis[v] = vis[u] ^ 1;
            go(v);
        }
    }; vis[1] = 0; go(1);

    vi cnt(2);
    rep(i, 1, n + 1) cnt[vis[i]]++;
    int ch = 0;
    if(cnt[1] < cnt[0]) ch = 1;

    vi ans;
    rep(i, 1, n + 1) if(vis[i] == ch) ans.emplace_back(i);
    cout << sz(ans) << "\n";
    rep(i, 0, sz(ans)) cout << ans[i] << " \n"[i == sz(ans) - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}