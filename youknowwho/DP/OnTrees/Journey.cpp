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

const int N = 1e5 + 5;
int n;
vi g[N];

double ans = 0;
void go(int u, int p, double prob, int d){
    if(sz(g[u]) == 1 && u != 0){
        ans += prob * (d - 1);
        return; 
    }

    double nprob = double(1) / double(sz(g[u]) + (u ? -1 : 0));
    for(auto v : g[u]){
        if(v == p) continue;
        go(v, u, prob * nprob, d + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);

    cin >> n;
    rep(i, 0, n - 1){
        int u, v; cin >> u >> v; u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }   

    go(0, -1, 1.0, 1);
    cout << ans << "\n";
}