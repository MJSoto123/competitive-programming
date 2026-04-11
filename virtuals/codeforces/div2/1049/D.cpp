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
    vvi a(n, vi(2));
    rep(i, 0, n) cin >> a[i][0] >> a[i][1];

    ll ans = 0;
    rep(i, 0, n) ans += a[i][1] - a[i][0];

    vvi ord(2, vi(n));
    iota(all(ord[0]), 0);
    iota(all(ord[1]), 0);

    sort(all(ord[0]), [&](int i, int j){
        return a[i][0] < a[j][0];
    });
    sort(all(ord[1]), [&](int i , int j){
        return a[i][1] > a[j][1];
    });

    vi id(2, 0);
    while(id[0] < n && id[1] < n){
        int nowl = ord[0][id[0]];
        int nowr = ord[1][id[1]];

        if(nowl == nowr){
            // nowl - nowr2
            ll ans1 = 0;
            {
                
            }

            // nowl2 - nowl
        }else{
            ans += a[nowr][1] - a[nowl][0];
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}