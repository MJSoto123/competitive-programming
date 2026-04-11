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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vvi g(n + 1);
    rep(v, 2, n + 1){
        int u; cin >> u;
        g[u].emplace_back(v);
    }

    vi dp(n + 1);
    function<void(int)> go = [&](int u){
        for(auto v : g[u]){
            go(v);
            dp[u] += 1 + dp[v];
        }
    };

    go(1);
    rep(i, 1, n + 1) cout << dp[i] << " \n"[i == n];
}