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

    int n, m; cin >> n >> m;
    vvi g(n + 1);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi team(n + 1);
    queue<int> q;
    rep(i, 1, n + 1){
        if(team[i]) continue;
        team[i] = 1;
        q.emplace(i);
        
        while(sz(q)){
            int u = q.front(); q.pop();
            for(auto v : g[u]){
                if(team[v] && team[v] == team[u]){ cout << "IMPOSSIBLE\n"; return 0; }
                if(team[v]) continue;
                team[v] = (team[u] == 1 ? 2 : 1);
                q.emplace(v);
            }
        }
    }

    rep(i, 1, n + 1) cout << team[i] % 2 + 1 << " \n"[i == n];
}