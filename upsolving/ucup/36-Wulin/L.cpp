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

const int N = 1e5 + 10;
vi g[N];
int vis[N];
int par[N];
int n;

vi cyc;
void search(int u, int p){
    if(sz(cyc)) return;
    for(auto v : g[u]){
        if(vis[v]){
            int cur = par[v];
            while(cur != v){
                cyc.emplace_back(cur);
                cur = par[v];
            }
            cyc.emplace_back(cur);
            return;
        }
        vis[v] = 1;
        par[v] = u;
        search(v, u);
    }
}

int solve(int p){
    cout << "\nsolve " << p << "\n";
    cyc.clear();
    int ans = 0;
    par[p] = p; vis[p] = 1; search(p, p);

    for(auto x : cyc) cout << x << " "; cout << "\n";

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    rep(u, 1, n + 1){
        int v; cin >> v;
        g[v].emplace_back(u);
    }

    ll ans = 0;

    rep(i, 1, n + 1){
        if(vis[i]) continue;
        vis[i] = 1; 
        ans += solve(i);
    }

    cout << ans << '\n';
}