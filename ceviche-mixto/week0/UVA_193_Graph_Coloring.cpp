#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)
#define dbg(a) cerr << (#a) << " "; for(auto x : a) cerr << x << " "; cerr << "\n";

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int n, m;
const int N = 100 + 1;
vector<bitset<N>> g(N);
vi ans, cur, ord;

void init(){
    rep(u, 0, N) g[u].reset();
    ans.clear();
}

int get(bitset<N> &alive){
    rep(bit, 0, n) if(alive[bit]) return bit;
    return -1;
}

void go(bitset<N> alive, int id){
    // bound
    if(sz(cur) + alive.count() <= sz(ans)) return;

    // update
    if(id == n || alive.none()){
        if(sz(cur) > sz(ans)) ans = cur;
        return;
    }

    // pick
    int u = get(alive);
    if(u == -1) return;
    
    bitset<N> tmp;
    // include
    {
        cur.emplace_back(u);
        tmp = alive & (~g[u]);
        tmp.reset(u);
        go(tmp, id + 1);
        cur.pop_back();
    }

    // exclude
    {
        tmp = alive;
        tmp.reset(u);
        go(tmp, id + 1);
    }
}

void solve(){
    init();

    cin >> n >> m;
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].set(v);
        g[v].set(u);
    }
    // iota(all(ord), 0);
    // sort(all(ord), [&](int u, int v){ return g[u].count() > g[v].count(); });

    bitset<N> tmp;
    rep(i, 0, n) tmp.set(i);
    go(tmp, 0);
    cout << sz(ans) << "\n";
    rep(i, 0, sz(ans)){
        if(i) cout << " ";
        cout << ans[i] + 1;
    }
    cout << "\n";;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}