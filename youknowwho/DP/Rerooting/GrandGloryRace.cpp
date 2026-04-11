#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct Edge { int to; int w; };

const ll INF = (ll)4e18;
const int SELF = -1;

int n;
vector<vector<Edge>> g;
vector<vector<pair<int,int>>> queriesAt;
vector<ll> ans;

vector<int> parent_, parentW;
vector<ll> downDist;
vector<int> downLeaf;
vector<ll> upDist;
vector<int> upLeaf;
vector<int> deg;
vector<char> isLeaf;

struct Cand {
    ll dist; int leaf; int source; bool valid;
};
inline bool better(const Cand& a, const Cand& b){
    if(!a.valid) return false;
    if(!b.valid) return true;
    if(a.dist != b.dist) return a.dist < b.dist;
    return a.leaf < b.leaf;
}
vector<Cand> best1, best2;

vector<int> currBestLeaf;
vector<int> claimedCount;

void dfs1(int u, int p){
    parent_[u] = p;
    if(isLeaf[u]) { downDist[u] = 0; downLeaf[u] = u; }
    for(const auto &e : g[u]){
        int v = e.to; int w = e.w;
        if(v==p) continue;
        dfs1(v,u);
        ll candD = downDist[v] + w;
        int candL = downLeaf[v];
        if(candD < downDist[u] || (candD == downDist[u] && candL < downLeaf[u])){
            downDist[u] = candD;
            downLeaf[u] = candL;
        }
    }
}

void dfs2(int u, int p){
    Cand c1{INF,-1,-2,false}, c2{INF,-1,-2,false};
    auto push_best = [&](Cand c){
        if(!c.valid) return;
        if(better(c, c1)){ c2 = c1; c1 = c; }
        else if(better(c, c2)){ c2 = c; }
    };

    for(const auto& e : g[u]){
        int v = e.to, w = e.w;
        if(v==p) continue;
        Cand c{downDist[v] + w, downLeaf[v], v, true};
        push_best(c);
    }

    for(const auto& e : g[u]){
        int v = e.to, w = e.w;
        if(v==p) continue;

        Cand bestExcl{INF,-1,-2,false};
        if(isLeaf[u]){
            Cand sc{0, u, SELF, true};
            if(better(sc, bestExcl)) bestExcl = sc;
        }
        if(upDist[u] < INF){
            Cand uc{upDist[u], upLeaf[u], parent_[u], true};
            if(better(uc, bestExcl)) bestExcl = uc;
        }
        Cand chooseChild = (c1.valid && c1.source!=v) ? c1 : c2;
        if(chooseChild.valid){
            if(better(chooseChild, bestExcl)) bestExcl = chooseChild;
        }

        upDist[v] = (bestExcl.valid ? bestExcl.dist + w : INF);
        upLeaf[v] = (bestExcl.valid ? bestExcl.leaf     : -1);

        dfs2(v,u);
    }
}

void buildBestPairs(){
    best1.assign(n, Cand{INF,-1,-2,false});
    best2.assign(n, Cand{INF,-1,-2,false});

    auto push = [&](int u, Cand c){
        if(!c.valid) return;
        if(better(c, best1[u])){ best2[u] = best1[u]; best1[u] = c; }
        else if(better(c, best2[u])){ best2[u] = c; }
    };

    for(int u=0; u<n; ++u){
        if(parent_[u]!=-1 && upDist[u] < INF){
            push(u, Cand{upDist[u], upLeaf[u], parent_[u], true});
        }
        for(const auto& e : g[u]){
            int v = e.to, w = e.w;
            if(v==parent_[u]) continue;
            push(u, Cand{downDist[v]+w, downLeaf[v], v, true});
        }
        if(isLeaf[u]){
            push(u, Cand{0, u, SELF, true});
        }
    }
}

int chooseLeaf(int u, int excludeSource){
    if(excludeSource == -2) return best1[u].leaf;
    if(best1[u].source != excludeSource) return best1[u].leaf;
    return best2[u].leaf;
}

void initStateRoot0(){
    currBestLeaf.assign(n, -1);
    claimedCount.assign(n, 0);
    for(int u=0; u<n; ++u){
        int excl = (parent_[u]==-1 ? -2 : parent_[u]);
        int leaf = chooseLeaf(u, excl);
        currBestLeaf[u] = leaf;
        if(leaf!=-1) claimedCount[leaf]++;
    }
}

void applyChange(int u, int newLeaf){
    int oldLeaf = currBestLeaf[u];
    if(oldLeaf == newLeaf) return;

    if(oldLeaf != -1) claimedCount[oldLeaf]--;
    if(newLeaf != -1) claimedCount[newLeaf]++;
    currBestLeaf[u] = newLeaf;
}

void solveQueriesAt(int t){
    for(auto &qs : queriesAt[t]){
        int id = qs.first;
        int s  = qs.second;
        ans[id] = claimedCount[s];
    }
}

void dfsReroot(int u){
    solveQueriesAt(u);

    for(const auto& e : g[u]){
        int w = e.to;
        if(w==parent_[u]) continue;

        int u_new = chooseLeaf(u, w);
        int u_old_root = chooseLeaf(u, -2);
        applyChange(u, u_new);

        int w_old = chooseLeaf(w, u);
        int w_new_root = chooseLeaf(w, -2);
        applyChange(w, w_new_root);
        dfsReroot(w);
        applyChange(w, w_old);
        applyChange(u, u_old_root);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.assign(n, {});
    deg.assign(n, 0);

    for(int i=0;i<n-1;i++){
        int u,v,w; cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        deg[u]++; deg[v]++;
    }

    isLeaf.assign(n, 0);
    for(int i=0;i<n;i++){
        if(deg[i] <= 1) isLeaf[i] = 1;
    }

    int q; cin >> q;
    queriesAt.assign(n, {});
    ans.assign(q, 0);
    for(int i=0;i<q;i++){
        int s,t; cin >> s >> t;
        --s; --t;
        queriesAt[t].push_back({i,s});
    }

    parent_.assign(n, -1);
    parentW.assign(n, 0);
    downDist.assign(n, INF);
    downLeaf.assign(n, -1);
    upDist.assign(n, INF);
    upLeaf.assign(n, -1);

    dfs1(0, -1);

    upDist[0] = INF; upLeaf[0] = -1;
    dfs2(0, -1);

    buildBestPairs();
    initStateRoot0();
    dfsReroot(0);

    for(int i=0;i<q;i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
