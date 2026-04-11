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

const int N = 500000 + 10;
int Sz[N];
int par[N];
int mn[N];
int a[N];

void init(int n){
    rep(i, 0, n) Sz[i] = 1, par[i] = i, mn[i] = a[i];
}

int get(int u){
    return par[u] == u ? u : get(par[u]);
}

void unite(int u, int v){
    u = get(u), v = get(v);
    if(u == v) return;
    if(Sz[u] < Sz[v]) swap(u, v);

    Sz[u] += Sz[v];
    par[v] = u;
    mn[u] = min(mn[u], mn[v]);
}


void solve(){
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    
    auto f = [&](int h){
        init(n);
        rep(i, 0, n){
            if(i + 1 < n && a[i] - h <= a[i + 1] && a[i] + h >= a[i + 1]) unite(i, i + 1);
        }

        int mx = 0;
        rep(i, 0, n) mx = max(mx, mn[get(i)]);
        return (mx <= h);
    };
    
    int l = -1, r = 1e9 + 100;
    while(r - l > 1){
        int mid = l + r >> 1;
        if(f(mid)) r = mid;
        else l = mid;
    }

    cout << r << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    for(int i = 1; i <= tt; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}