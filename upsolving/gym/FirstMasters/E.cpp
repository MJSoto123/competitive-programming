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

    int n, m, k; cin >> n >> m >> k;
    vvi g(n + 1);

    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi vis(n + 1, 0);
    queue<pii> q;
    rep(i, 0, k){
        int x; cin >> x;
        q.emplace(x, 0);
        vis[x] = 2;
    }

    while(sz(q)){
        auto [u, d] = q.front(); q.pop();
        if(u == 1){ cout << d << "\n"; return 0; }
        for(auto v : g[u]){
            if(vis[v] == 2) continue;
            vis[v]++;
            if(vis[v] == 2) q.emplace(v, d + 1);
        }
    }
    cout << "-1\n";
}