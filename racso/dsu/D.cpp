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
int par[N];
int Sz[N];

void init(){
    rep(i, 0, N) par[i] = i, Sz[i] = 1;
}

int get(int u){
    return par[u] = (u == par[u] ? u : get(par[u]));
}

void unite(int u, int v){
    u = get(u), v = get(v);
    if(u == v) return;
    if(Sz[u] < Sz[v]) swap(u, v);

    par[v] = u;
    Sz[u] += Sz[v];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int n, ed, qq; cin >> n>> ed >> qq;
    rep(i, 0, ed){ int u, v; cin >> u >> v; }

    vii edges(qq);
    vi t(qq);

    rep(i, 0, qq){
        string s; int u, v; cin >> s >> u >> v;
        t[i] = (s == "ask");
        edges[i] = {u, v};
    }

    reverse(all(edges));
    reverse(all(t));
    
    vector<string> ans;
    rep(i, 0, qq){
        auto [u, v] = edges[i];
        if(t[i]){
            if(get(u) == get(v)) ans.emplace_back("YES");
            else ans.emplace_back("NO");
        }else unite(u, v);
    }

    reverse(all(ans));
    for(auto x : ans) cout << x << "\n";
}