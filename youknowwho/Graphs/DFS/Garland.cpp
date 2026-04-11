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

vvi g;
vi a, ans;

int sm = 0, root;
int go(int u){
    int curr = 0;
    for(auto v : g[u]) curr += go(v);
    curr += a[u];
    if(curr == sm / 3){
        ans.emplace_back(u);
        return 0;
    }
    return curr;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    g.resize(n + 1);
    a.resize(n + 1);

    for(int u = 1; u <= n; u++){
        int p, t; cin >> p >> t;
        g[p].emplace_back(u);
        a[u] = t;
    }   

    sm = accumulate(all(a), 0);
    if(sm % 3){ cout << "-1\n"; return 0; }
    
    int root = g[0][0];
    go(root);

    if(sz(ans) <= 2){ cout << "-1\n"; return 0; }
    cout << ans[0] << " " << ans[1] << "\n";
}