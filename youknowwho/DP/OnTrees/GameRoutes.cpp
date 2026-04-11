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

const int MOD = 1e9 + 7;
int add(int a, int b){ return a + b >= MOD ? a + b - MOD : a + b; }

const int N = 1e5 + 10;
int n, m;

vi g[N];
int in[N];
int dp[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        g[u].emplace_back(v);
        in[v]++;
    }

    vi ord;
    queue<int> q;
    rep(u, 0, n) if(in[u] == 0) q.emplace(u);

    while(sz(q)){
        int u = q.front(); q.pop();
        ord.emplace_back(u);
        for(auto v : g[u]){
            in[v]--;
            if(in[v] == 0) q.emplace(v);
        }
    }
    
    dp[0] = 1;
    for(auto u : ord){
        for(auto v : g[u]) dp[v] = add(dp[v], dp[u]);
    }

    cout << dp[n - 1] << "\n";
}