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
int n, m;
vi g[N];
int dp[N];
int in[N];

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
    rep(u, 0, n) if(in[u] == 0){
        q.emplace(u);
        dp[u] = 1;
    }

    while(sz(q)){
        int u = q.front(); q.pop();
        ord.emplace_back(u);
        for(auto v : g[u]){
            in[v]--;
            if(in[v] == 0) q.emplace(v);
        }
    }

    
    for(auto u : ord){
        for(auto v : g[u]) dp[v] = max(dp[v], dp[u] + 1);
    }

    cout << *max_element(all(dp)) - 1 << "\n";
}