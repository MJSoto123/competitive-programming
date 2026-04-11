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

    int n, m; cin >> n >> m;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    auto f = [&](int tar){
        ll ans = 0;
        for(int i = 0; i < n; i++) if(a[i] < tar) ans += (tar - a[i]);
        for(int i = 0; i < m; i++) if(b[i] > tar) ans += (b[i] - tar);
        return ans;
    };

    int l = 0, r = 1e9;
    while(r - l > 3){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if(f(m1) < f(m2)) r = m2;
        else l = m1;
    }

    ll ans = 1e18;
    for(int i = l; i <= r; i++) ans = min(ans, f(i));
    
    cout << ans << "\n";
}