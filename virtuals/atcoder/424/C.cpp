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
    queue<int> q;
    rep(i, 0, n){
        int u, v; cin >> u >> v;
        if(u == 0 && v == 0) q.emplace(i + 1);
        else{
            g[u].emplace_back(i + 1);
            g[v].emplace_back(i + 1);
        }
    }

    int ans = 0;
    vi vis(n + 1);
    while(sz(q)){
        int u = q.front(); q.pop();
        if(!vis[u]) ans++;
        vis[u] = 1;
        for(auto v : g[u]){
            if(vis[v]) continue;
            vis[v] = 1;
            ans++;
            q.emplace(v);
        }
    }

    cout << ans << "\n";
}