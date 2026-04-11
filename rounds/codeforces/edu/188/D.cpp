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
    vvi g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int ans = 0;
    vi vis(n, -1);
    rep(i, 0, n){
        if(vis[i] != -1) continue;
        queue<int> q;
        q.emplace(i);
        vis[i] = 0;

        int ze = 1;
        int ones = 0;
        bool contra = 0;
        while(sz(q)){
            int u = q.front(); q.pop();
            int color = vis[u];
            for(auto v : g[u]){
                if(vis[v] != -1){
                    if(vis[v] == vis[u]) contra = 1;
                    continue;
                }
                vis[v] = color ^ 1;
                if(color) ze++;
                else ones++;

                q.emplace(v);
            }
        }

        if(!contra) ans += max(ze, ones);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}