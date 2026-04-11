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

    int n, m, s; cin >> n >> m >> s;
    vector<vii> g(n);
    rep(i, 0, m){
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    vl d(n, -1);
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.emplace(0, s);

    while(sz(q)){
        auto [dist, u] = q.top(); q.pop();
        if(dist != d[u]) continue;
        for(auto [v, w] : g[u]){
            if(d[v] == -1 || d[u] + w < d[v]){
                d[v] = d[u] + w;
                q.emplace(d[v], v);
            }
        }
    } 

    rep(i, 0, n){
        if(d[i] == -1) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}