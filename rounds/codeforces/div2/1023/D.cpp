#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

int mxd = 0;
pair<int, int> mx;
pair<int, int> getdiam(int u, int p, int old){
    pair<int, int> a = {0, u};
    pair<int, int> b = {0, u};
    for(int v : g[u]){
        if(v == p || vis[v] != old) continue;
        auto [dis, to] = getdiam(v, u, old); dis++;
        pair<int, int> cur = {dis, to};

        if(cur > a){
            b = a;
            a = cur;
        } else if(cur > b) b = cur;
    }

    int total = a.first + b.first;
    pair<int, int> now = {max(a.second, b.second), min(a.second, b.second)};

    if(total > mxd){
        mxd = total;
        mx = now;
    } else if(total == mxd) mx = max(mx, now);
    return a;
}

vector<int> path;
void getpath(int u, int to, int p,int old){
    path.emplace_back(u);
    if(u == to) return;
    for(auto v : g[u]){
        if(v == p || vis[v] == 0 || vis[v] != old) continue;
        getpath(v, to, u, old);
        if(path.back() == to) return;
    }
    path.pop_back();
}

void mark(int u, int old, int id){
    vis[u] = id;
    for(auto v : g[u]){
        if(vis[v] == 0 || vis[v] != old) continue;
        vis[v] = id;
        mark(v, old, id);
    }
}

void solve(){
    int n; cin >> n;
    if(n == 1) {cout << "1 1 1\n"; return;}
    g.assign(n + 1, vector<int> ());
    vis.assign(n + 1, 1);

    for(int i = 0; i < n - 1; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int color = 2;

    priority_queue<tuple<int, int, int>> q;
    vector<tuple<int, int, int>> ans;

    mxd = 0; mx = {0, 0};
    getdiam(1, -1, color - 1);
    q.emplace(mxd, mx.first, mx.second);

    while (!q.empty()){
        int d, u, v; tie(d, u, v) = q.top(); q.pop();
        int old = vis[u];
        
        path.clear();
        getpath(u, v, -1, old);
        for(auto x : path) vis[x] = 0;
        
        ans.emplace_back(path.size(), u, v);
        for(int w = 1; w <= n; w++){
            if(old == vis[w]){
                mark(w, old, color++);

                mxd = 0; mx = {0, 0};
                getdiam(w, -1, color - 1);

                if(mxd == 0) ans.emplace_back(1, w, w);
                else q.emplace(mxd, mx.first, mx.second);
            }
        }
    }

    sort(ans.rbegin(), ans.rend());
    for(auto [d, u, v] : ans) cout << d << " " << u << " " << v << " ";
    cout << "\n";
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();
}