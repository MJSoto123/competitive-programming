#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

vi par, mn, mx, sz;
void init(int n){
    par.resize(n + 1);
    sz.resize(n + 1, 1);
    mn.assign(n + 1, 1e9);
    mx.assign(n + 1, 0);
    for(int i = 0; i <= n; i++) par[i] = i;
}

int get(int u){
    return par[u] = ((par[u] == u) ? u : get(par[u]));
}

void unite(int u, int v, int w){
    int pu = get(u);
    int pv = get(v);
    if(pu == pv) return;
    
    // u > v
    if(sz[pu] < sz[pv]) swap(pu, pv);
    par[pv] = pu;
    sz[pu] += sz[pv];
    mn[pu] = min(mn[pv], min(mn[pu], w));
    mx[pu] = max(mx[pv], max(mn[pu], w));
}

void solve(){
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> a(m);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        a[i] = make_tuple(w, u, v);
    }

    init(n + 1);
    sort(a.begin(), a.end());
    int ans = 2e9 + 100;
    for(auto [w, u, v] : a){
        unite(u, v, w);
        if(get(1) == get(n)) ans = min(ans, mn[get(1)] + mx[get(1)]);
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}