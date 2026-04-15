#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)
#define dbg(a) cerr << (#a) << "\t"; for(auto x : a) cerr << x << " "; cerr << "\n";

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<ll , ll> pii;
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> g;
    rep(i, 0, m){
        int u, v, w; cin >> u >> v >> w;
        g.emplace_back(make_tuple(u, v, w));
    }

    vl d(n + 1, 1e18);
    d[1] = 0;

    vi p(n + 1);
    int cyc = 0;
    rep(i, 0, n){
        cyc = 0;
        for(auto [u, v, w] : g){
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                p[v] = u;
                cyc = v;
            }
        }
        // dbg(d);
    }

    if(cyc == 0){ cout << "NO\n"; return 0;}
    cout << "YES\n";
    rep(i, 0, n) cyc = p[cyc];

    vi path(1, cyc);
    int cur = p[cyc];
    while(cur != cyc){
        path.emplace_back(cur);
        cur = p[cur];
    }
    path.emplace_back(cur);
    reverse(all(path));
    for(auto x : path) cout << x << " "; cout << "\n";
}