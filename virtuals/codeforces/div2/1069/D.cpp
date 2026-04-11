#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<int> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];   
    vi fs(k + 1, -1); 
    rep(i, 0, n){
        rep(j, 0, a[i] + 1) if(fs[j] == -1) fs[j] = i;
    }
    
    // laputamadre
    int mx = 0;
    rep(i, 0, k + 1) rep(j, 0, k + 1) mx = max(mx, dp[i][j]);
    cout << mx << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}