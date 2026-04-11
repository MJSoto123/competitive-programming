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

int n; 
vi g[N];
int vis[N];

int ans = 0;
int get(int u, int p = -1){
    int mx = 0, mx2 = 0;
    for(auto v : g[u]){
        if(v == p) continue;
        int here = get(v, u);
        if(here >= mx){
            mx2 = mx;
            mx = here;
        } else {
            mx2 = max(mx2, here);
        }
    }

    ans = max(ans, mx + mx2 + 1);
    ans = max(ans, 1);
    return 1 + max(mx, mx2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    rep(i, 0, n - 1){
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    get(1);

    cout << ans - 1 << "\n";
}