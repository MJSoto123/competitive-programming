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
    rep(i, 1, n){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi team(n + 1, -1);
    function<void(int)> go = [&](int u){
        for(auto v : g[u]){
            if(team[v] != -1) continue;
            team[v] = team[u] ^ 1;
            go(v);
        }
    };
    
    team[1] = 0;
    go(1);

    vi cnt(2);
    rep(i, 0, 2) cnt[i] = count(all(team), i);

    ll ans = 0;
    rep(u, 1, n + 1){
        int deg = sz(g[u]);
        if(team[u] == 0) ans += (cnt[1] - deg);
        else ans += (cnt[0] - deg);
    }

    cout << ans / 2 << "\n";
}