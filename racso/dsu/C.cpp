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
const int N = 2e5 + 5;
int Sz[N];
int val[N];
int par[N];

void init(){
    rep(i, 0, N) Sz[i] = 1, val[i] = 0, par[i] = i;
}

int get(int u){
    if(u == par[u]) return u;
    return get(par[u]);
}

void unite(int u, int v){
    u = get(u), v = get(v);
    if(u == v) return;
    if(Sz[u] < Sz[v]) swap(u, v);

    Sz[u] += Sz[v];
    par[v] = u;
    val[v] = val[v] - val[u];
}

void add(int u, int x){
    u = get(u);
    val[u] += x;
}

int ans(int u){
    if(u == par[u]) return val[u];
    return val[u] + ans(par[u]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    init();

    rep(i, 0, m){
        string op; cin >> op;
        if(op == "add"){
            int u, x; cin >> u >> x; 
            add(u, x);
        }else if(op == "join"){
            int u, v; cin >> u >> v;
            unite(u, v);
        }else{
            int u; cin >> u;
            cout << ans(u) << "\n";
        }
    }
}