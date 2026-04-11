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
    vl f(n);
    rep(i, 0, n) cin >> f[i];
    
    vl a(n);
    ll pre = 0;

    ll sum = (f[0] + f[n - 1]) / (n - 1);
    rep(i, 0, n - 1){
        a[i] = -(f[i] - f[i + 1] - sum + 2 * pre);
        a[i] /= 2;
        pre += a[i];
    }
    a[n - 1] = sum - pre;

    rep(i, 0, n) cout << a[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}