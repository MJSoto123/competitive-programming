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

const int N = 3e5 + 100;
int add(int a, int b, int mod){ return (a + b >= mod ? a + b - mod : a + b); }
int mul(ll a, ll b, int mod){ return (a * b) % mod; }
const int b[] = {int(1e9 + 7), int(1e9 + 9)};
const int m[] = {int(1e9 + 21), int(1e9 + 33)};
int pot[N][2];

void init(){
    pot[0][0] = pot[0][1] = 1;
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 2; j++) pot[i][j] = mul(pot[i - 1][j], b[j], m[j]); 
    }
}

pii H(vi &a){
    vi h(2);
    for(int i = 0; i < sz(a); i++){
        for(int j = 0; j < 2; j++) h[j] = add(h[j], mul(a[i], pot[i][j], m[j]), m[j]);
    }
    return make_pair(h[0], h[1]);
}

int Sz[N];
int Par[N];
int get(int u){ return (u == Par[u] ? u : Par[u] = get(Par[u])); }
void unite(int u, int v){
    u = get(u); v = get(v);
    if(Sz[u] < Sz[v]) swap(u, v);
    Par[v] = u;
    Sz[u] += Sz[v];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();

    int n, m; cin >> n >> m;
    vvi g(n);
    vii edges(m);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        edges[i] = {u, v};
    }

    for(int i = 0; i < n; i++){
        g[i].emplace_back(i);
        sort(all(g[i]));
    }
    
    vii hs(n);
    for(int i = 0; i < n; i++) hs[i] = H(g[i]);

    map<pii, int> mp;
    vi b(n, -1);
    for(int i = 0; i < n; i++){
        if(mp.count(hs[i])) b[i] = mp[hs[i]];
        else b[i] = mp[hs[i]] = sz(mp);
    }
    int n2 = sz(mp);

    // for(int i = 0; i < n; i++) cerr << b[i] << " "; cout << "\n";
    for(int i = 0; i < n2; i++) Par[i] = i;
    for(int i = 0; i < n2; i++) Sz[i] = 1;
    vvi g2(n2);
    for(auto [u, v] : edges){
        int pu = get(b[u]), pv = get(b[v]);
        if(pu == pv) continue;
        unite(b[u], b[v]);
        // cerr << "adding " << b[u] << " " << b[v] << "\n";
        g2[b[u]].emplace_back(b[v]);
        g2[b[v]].emplace_back(b[u]);
    }

    vi deg(n2);
    for(int i = 0; i < n2; i++) deg[i] = sz(g2[i]);
    // for(auto x : deg) cerr << x << " "; cout << "\n"; xdsdxas

    int twos = count(all(deg), 2);
    bool ok = twos != n2;
    for(auto x : deg) if(x > 2) ok = false;
    if(!ok){ cout << "NO\n"; return 0; }

    int root = 0;
    for(int i = 0; i < n2; i++){
        if(deg[i] == 1) root = i;
    }

    vi vis(n2, 0);
    function<void(int)> dfs = [&](int u){
        for(auto v : g2[u]){
            if(vis[v]) continue;
            vis[v] = vis[u] + 1;
            dfs(v);
        }
    };

    vis[root] = 1;
    dfs(root);

    cout << "YES\n";
    for(int i = 0; i < n; i++) cout << vis[b[i]] << " "; cout << "\n";
}