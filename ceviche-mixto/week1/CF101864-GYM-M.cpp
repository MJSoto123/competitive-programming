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

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int m; cin >> m;
    vi b(m);
    rep(i, 0, m) cin >> b[i];

    vi d(m, 0);
    vi c;
    for(int i = m - 1; i >= 0; i--){
        int q = b[i] / a.back();
        if(d == b) break; 
        c.emplace_back(q);
        if(q == 0) continue;
        for(int j = 0; j < n; j++) b[i - j] -= a[n - 1 - j] * q;
    }

    cout << sz(c) << "\n";
    reverse(all(c));
    for(auto x : c) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}