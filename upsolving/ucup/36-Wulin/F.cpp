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
    int n, m, k; cin >> n >> m >> k;
    vi col(n);
    vvi idcol(51);
    rep(i, 0, n){
        cin >> col[i];
        idcol[col[i]].emplace_back(i);
    }

    vvi g(n), inv(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--; v--;
        if(u == v) continue;
        g[u].emplace_back(v);
        inv[v].emplace_back(u);
    }

    vvi d(2, vi(n, 1e9)), from(2, vi(n, -1));
    int node1 = 1e8, node2 = 1e8 + 100;
    auto go = [&](int c){
        queue<tuple<int, int, int>> q;
        for(auto u : idcol[c]) q.emplace(0, u, u);
        while(sz(q)){
            auto [dist, u, par] = q.front(); q.pop();
            for(auto v : g[u]){
                // primera vez
                if(from[0][v] == -1){
                    d[0][v] = dist + 1;
                    from[0][v] = par;
                    q.emplace(dist + 1, v, par);
                }else{
                    // misma distancia
                    if(dist + 1 == d[0][v]) from[0][v] = node1;
                }
            }
        }
    };

    auto go2 = [&](int c){
        queue<tuple<int, int, int>> q;
        for(auto u : idcol[c]) q.emplace(0, u, u);
        
        while(sz(q)){
            auto [dist, u, par] = q.front(); q.pop();
            for(auto v : inv[u]){
                // primera vez
                if(from[1][v] == -1){
                    d[1][v] = dist + 1;
                    from[1][v] = par;
                    q.emplace(dist + 1, v, par);
                }else{
                    // misma distancia
                    if(dist + 1 == d[1][v]) from[1][v] = node2;
                }
            }
        }
    };

    rep(c, 1, 51){
        go(c); go2(c);
        rep(u, 0, n){
            if(from[0][u] == -1 || from[1][u] == -1){
                if(from[0][u] != -1 && col[u] == c && d[0][u] + 1 <= k){ cout << "NO\n"; return; }
                if(from[1][u] != -1 && col[u] == c && d[1][u] + 1 <= k){ cout << "NO\n"; return; }
                continue;
            }
            if(from[0][u] == from[1][u]) continue;
            int dist = d[0][u] + d[1][u] + 1;
            if(dist <= k){ cout << "NO\n"; return; }
        }

        d.assign(2, vi(n, 1e9));
        from.assign(2, vi(n, -1));
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}