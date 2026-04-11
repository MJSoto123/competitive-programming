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

    int n; ll h, k; cin >> n >> h >> k;
    vi x(n), y(n), t(n);
    rep(i, 0, n) cin >> x[i] >> y[i] >> t[i];

    int sx, sy; cin >> sx >> sy;
    int id = 0;
    rep(i, 0, n) if(x[i] == sx && y[i] == sy) id = i;
    if(sy == 0){ cout << "0\n"; return 0; }

    auto dist = [&](int u, int v){
        ll dx = x[u] - x[v];
        ll dy = y[u] - y[v];
        return dx * dx + dy * dy;
    };

    queue<pii> q; q.emplace(id, 0);
    vi vis(n); vis[id] = 1;
    while(sz(q)){
        auto [u, d] = q.front(); q.pop();
        if(t[u] && abs(y[u]) <= h){ cout << d + 1 << "\n"; return 0; }

        rep(v, 0, n){
            if(vis[v]) continue;
            if(x[v] == x[u] && y[v] == y[u]){ q.emplace(v, d); continue; }
            
            if(t[u] && dist(u, v) <= h * h || t[v] && dist(u, v) <= k * k){
                vis[v] = 1; 
                q.emplace(v, d + 1); 
            }
        }
    }

    cout << "-1\n";
}