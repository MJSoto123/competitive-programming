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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi pre(n);
    pre[0] = a[0];
    rep(i, 1, n) pre[i] = __gcd(pre[i - 1], a[i]);
    
    vi suf(n);
    suf[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) suf[i] = __gcd(suf[i + 1], a[i]);
    
    
    ll ans = pre[n - 1];
    rep(i, 1, n - 1) ans += min(pre[i], suf[i]);
    cout << ans << "\n";
}