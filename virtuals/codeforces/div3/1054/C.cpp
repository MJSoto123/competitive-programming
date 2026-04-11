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
    int n, k; cin >> n >> k;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int falta = 0;
    int sobra = 0;
    vi cnt(n + 2, 0);
    rep(i, 0, n) cnt[a[i]]++;
    rep(i, 0, k) {
        if(cnt[i] == 0) falta++;
        else sobra += (cnt[i] - 1);
    }
    cout << max(falta, cnt[k]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}