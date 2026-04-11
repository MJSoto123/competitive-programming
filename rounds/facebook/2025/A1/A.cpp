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

    rep(h, 0, 200){
        int cur = a[0];
        bool ok = true;
        rep(i, 1, n){
            if(cur - h <= a[i] && cur + h >= a[i]) cur = a[i];
            else ok = false;
        }

        if(ok){ cout << h << "\n"; return; }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    for(int i = 1; i <= tt; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}