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
    int n; cin >> n;
    vvi g(n + 1);
    vi in(n + 1);
    rep(i, 1, n){
        int u, v; cin >> u >> v;
        int x, y; cin >> x >> y;
        if(x > y){ g[u].emplace_back(v); in[v]++; }
        else{ g[v].emplace_back(u); in[u]++; }
    }

    queue<int> q;
    rep(i, 1, n + 1) if(in[i] == 0) q.emplace(i);

    vi ord;
    while(sz(q)){
        int u = q.front(); q.pop();
        ord.emplace_back(u);
        for(auto v : g[u]){
            in[v]--;
            if(in[v] <= 0) q.emplace(v);
        }
    };

    reverse(all(ord));
    vi ans(n + 1);
    int cur = 1;
    rep(i, 0, sz(ord)){ ans[ord[i]] = cur; cur++; }

    rep(i, 1, n + 1) cout << ans[i] << " \n"[i == n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}