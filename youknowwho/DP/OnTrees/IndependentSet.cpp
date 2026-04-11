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

const int MOD = 1e9 + 7;
int add(int a, int b){ return (a + b >= MOD ? a + b - MOD : a + b); }
int mul(ll a, ll b){ return (a * b) % MOD; }

const int N = 1e5 + 5;
int n;
vi g[N];
int dp[N][2];

void get(int u, int p = -1){
    for(auto v : g[u]){
        if(v == p) continue;
        get(v, u);
        dp[u][0] = mul(dp[u][0], add(dp[v][0], dp[v][1]));
        dp[u][1] = mul(dp[u][1], dp[v][0]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    rep(i, 0, n - 1){
        int u, v; cin >> u >> v; u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    rep(i, 0, n) rep(j, 0, 2) dp[i][j] = 1;
    get(0);
    cout << add(dp[0][0], dp[0][1]) << "\n";
}