#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

void solve(){
    int n; cin >> n;
    vi deg(n + 1);
    vvi g(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        deg[u]++;
        deg[v]++;
    }

    if(n == 2){ cout << "0\n"; return; }

    int cnt = count(deg.begin(), deg.end(), 1);
    int ans = 1e9;
    for(int u = 1; u <= n; u++){
        int now = 0;
        for(auto v : g[u]){
            if(deg[v] == 1) now++;
        }
        ans = min(ans, cnt - now);
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}