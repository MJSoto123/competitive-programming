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

    int n, q; cin >> n >> q;
    vii a(n);
    rep(i, 0, n) cin >> a[i].first >> a[i].second;

    auto get = [&](pii x){
        int g = __gcd(abs(x.first), abs(x.second));
        return make_pair(x.first / g, x.second / g);
    };

    map<pii, int> mp;
    for(auto x : a) mp[get(x)]++;

    vii aux;
    for(auto [p, cnt] : mp) aux.emplace_back(p);
    
    sort(all(aux), [&](pii i, pii j){
        return atan2(i.second, i.first) < atan2(j.second, j.first);
    });

    map<pii, int> id;
    int m = sz(aux);
    rep(i, 0, m) id[aux[i]] = i;
    
    vi b(m);
    rep(i, 0, m) b[i] = mp[aux[i]];
    vi pre(m + 1);
    rep(i, 0, m) pre[i + 1] = pre[i] + b[i];

    function<int(int, int)> sm = [&](int l, int r){
        if(l <= r) return pre[r + 1] - pre[l];
        return pre[m] - pre[l] + pre[r + 1]; 
    };

    rep(i, 0, q){
        int u, v; cin >> u >> v;
        u--; v--;
        int idu = id[get(a[u])];
        int idv = id[get(a[v])];
        cout << sm(idu, idv) << "\n";
    }
}