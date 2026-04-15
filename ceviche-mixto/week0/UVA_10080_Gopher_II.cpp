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

// notebook 2023
struct mbm {
    int l, r;
    vvi g;
    vi match, vis;

    mbm(int l, int r) : l(l), r(r), g(l) {};
    void add_edge(int l, int r){ g[l].emplace_back(r); }

    bool dfs(int u){
        for(auto &v : g[u]){
            if(vis[v]++) continue;
            if(match[v] == -1 || dfs(match[v])){
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int max_matching(){
        int ans = 0;
        match.assign(r, -1);
        rep(u, 0, l){
            vis.assign(r, 0);
            ans += dfs(u);
        }
        return ans;
    }
};

double dist(double a, double b, double c, double d){
    return (c - a) * (c - a) + (d - b) * (d - b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    double s, v; 
    
    while(cin >> n >> m >> s >> v){
        double mx = s * v * s * v;
        
        vector<double> x(n), y(n);
        vector<double> x2(m), y2(m);
        
        rep(i, 0, n) cin >> x[i] >> y[i];
        rep(i, 0, m) cin >> x2[i] >> y2[i];
        
        mbm solver(n, m);
        rep(i, 0, n){
            rep(j, 0, m){
                double d = dist(x[i], y[i], x2[j], y2[j]);
                if(d <= mx) solver.add_edge(i, j);
            }
        }
        
        cout << n - solver.max_matching() << "\n";
    }
}   