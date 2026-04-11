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

const int MOD = 998244353;
int add(ll a, ll b){ return (a + b >= MOD ? a + b - MOD : a + b); }
int mul(ll a, ll b){ return (a * b) % MOD; }
void solve(){
    int n, m; cin >> n >> m;
    vvi g(n + 1);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    vi col(n + 1, -1);
    vi cnt(2);
    function<bool(int u)> go = [&](int u){
        bool ret = true;
        for(auto v : g[u]){
            if(col[v] != -1 && col[v] == col[u]) return false;
            if(col[v] != -1) continue;
            col[v] = col[u] ^ 1;
            cnt[col[v]]++;
            ret &= go(v);
        }
        return ret;
    };

    int ans = 1;
    rep(u, 1, n + 1){
        if(col[u] != -1) continue;
        col[u] = 0; cnt[0]++;
        
        bool ok = go(u);
        if(!ok){ cout << "0\n"; return; }

        int anshere = 0;
        rep(i, 0, 2){
            int now = 1;
            rep(j, 0, cnt[i]) now = mul(now, 2);
            anshere = add(anshere, now);
        }
        cnt[0] = cnt[1] = 0;
        ans = mul(ans, anshere);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();
}