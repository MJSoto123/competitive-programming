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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b; cin >> a >> b;
    map<ll, ll> g;
    g[a] = a;
    function<void(ll)> go = [&](ll u){
        for(auto v : {u * 2, u * 10 + 1}){
            if(v >= 1e9 + 100) continue;
            if(g.count(v)) continue;
            g[v] = u;
            go(v);
        }
    };

    go(a);
    if(!g.count(b)){ cout << "NO\n"; return 0; }

    vi path;
    while(b != a){
        path.emplace_back(b);
        b = g[b];
    }
    path.emplace_back(a);

    reverse(all(path));
    cout << "YES\n";
    cout << path.size() << "\n";
    for(auto u : path) cout << u << " ";
    cout << "\n";
}