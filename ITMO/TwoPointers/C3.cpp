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

    int n, d; cin >> n >> d;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    int r = 0;
    ll ans = 0;
    rep(l, 0, n){
        while(r < n && a[r] - a[l] <= d) r++;
        if(r < n && a[r] - a[l] > d) ans += (n - r);
    }
    cout << ans << "\n";
}