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
    ll sm; cin >> sm;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int l = 0;
    ll cur = 0;

    ll ans = 0;
    rep(r, 0, n){
        cur += a[r];
        while(cur > sm) cur -= a[l++];
        ans += (r - l + 1);
    }
    cout << ans << "\n";
}