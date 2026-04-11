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
    vector<vii> g(n + 1);
    rep(i, 1, n){
        int u, v, c; cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    function<int(int, int)> go = [&](int u, int p = -1){
        int ret = 0;
        for(auto [v, c] : g[u]){
            if(v == p) continue;
            ret = max(ret, c + go(v, u));
        }
        return ret;
    };
    cout << go(0, - 1) << "\n";
}   