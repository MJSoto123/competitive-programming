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

    int ans = 1e9;
    int r = 0;
    ll cur = 0;
    rep(l, 0, n){
        while(cur < sm && r < n) cur += a[r++];
        if(cur >= sm) ans = min(ans, r - l);
        cur -= a[l];
    }

    cout << (ans == 1e9 ? -1 : ans) << "\n";
}