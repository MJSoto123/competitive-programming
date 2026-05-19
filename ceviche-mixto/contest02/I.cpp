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

int n;
vvi g;
vi par;
vii cyc;
vi vis;
int timer = 1;
void dfs(int u, int p){
    for(auto v : g[u]){
        if(v == p) continue;

        if(par[v] == -2) par[v] = u;
        if(vis[v]){
            if(vis[v] > vis[u]) continue;
            cyc.emplace_back(u, v);
            continue;
        }
        vis[v] = timer++;
        dfs(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    g.resize(n);
    par.assign(n, -2);
    vis.resize(n);

    vi deg(n);
    rep(i, 0, n + 2){
        int u, v; cin >> u >> v;
        u--; v--;
        deg[u]++; deg[v]++;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi roots;
    rep(i, 0, n){
        if(deg[i] == 3) roots.emplace_back(i);
    }

    par[roots[0]] = -1;
    vis[roots[0]] = timer;
    {
        rep(i, 0, sz(g[roots[0]])){
            if(g[roots[0]][i] == roots[1]) swap(g[roots[0]][0], g[roots[0]][i]);
        }
    }
    dfs(roots[0], -1);

    vvi parts; 
    for(auto [from, to] : cyc){
        vi path(1, from);
        from = par[from];
        while(from != to){
            path.emplace_back(from);
            from = par[from];
        }
        path.emplace_back(to);
        parts.emplace_back(path);
    }

    vvi xd(3, vi(2));
    rep(i, 0, 3){
        for(auto u : parts[i]){
            if(deg[u] == 4) xd[i][0] = true;
            if(deg[u] == 3) xd[i][1] = true;
        }
    }

    int head;
    rep(i, 0, 3) if(xd[i][0] == 0) head = i;

    int tail;
    rep(i, 0, 3) if(xd[i][1] == 0) tail = i;

    int body = 3 - head - tail;

    cout << sz(parts[head]) << " " << sz(parts[body]) << " " << sz(parts[tail]) << "\n";
}