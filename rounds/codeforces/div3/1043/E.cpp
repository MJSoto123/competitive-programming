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

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vl a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];   
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(all(a)); reverse(all(a));
    sort(all(b)); reverse(all(b));

    vl prea(n + 1), preb(m + 1);
    for(int i = 0; i < n; i++) prea[i + 1] = prea[i] + a[i];
    for(int i = 0; i < m; i++) preb[i + 1] = preb[i] + b[i];

    ll inf = 8e18;
    auto f = [&](int x, int y, int z, int k){
        if(k < 0 || k > x || k > n || k > z) return -inf;
        if(z - k > y || z - k < 0 || z - k > m) return -inf;
        return prea[k] + preb[z - k];
    };

    for(int qq = 0; qq < q; qq++){
        int x, y, z; cin >> x >> y >> z;
        int l = max(0, z - y), r = min(x, z);
        while(r - l >= 3){
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if(f(x, y, z, m1) <= f(x, y, z, m2)) l = m1;
            else r = m2;
        }

        ll ans = 0;
        for(int i = l; i <= r; i++) ans = max(ans, f(x, y, z, i));
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}