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
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];   

    ll sm = 0;
    rep(i, 1, n) sm += abs(a[i] - a[i - 1]);

    ll ans = sm;
    vi b = a;
    b.pop_back();
    ll tmp = 0;
    rep(i, 1, sz(b)) tmp += abs(b[i] - b[i - 1]);
    ans = min(ans, tmp);

    b = a;
    reverse(all(b));
    b.pop_back();

    tmp = 0;
    rep(i, 1, sz(b)) tmp += abs(b[i] - b[i - 1]);
    ans = min(ans, tmp);

    rep(i, 1, n - 1){
        if(a[i - 1] <= a[i] && a[i] <= a[i + 1] || 
           a[i - 1] >= a[i] && a[i] >= a[i + 1]) continue;
        
        ll cur = sm - abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i]);
        cur += abs(a[i + 1] - a[i - 1]);
        ans = min(ans, cur);
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}