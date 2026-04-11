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
    vi cnt(2 * n + 1);
    rep(i, 0, 2 * n){
        int x; cin >> x;
        cnt[x]++;
    }

    int odd = 0, even = 0;;
    int tot = n;
    rep(i, 0, 2 * n + 1){
        if(cnt[i] == 0) continue;
        if(cnt[i] % 2) odd++;
        else even++;
    }
    tot = n - odd / 2;

    for(int ans = min(even, tot); ans >= 0; ans--){
        int here = n - ans;
        int mn = max(0, odd - here);
        int mx = min(odd, here);

        if(mx < 0 || mx < mn){
            // cerr << "wtf\n";
            continue;
        }

        if(mx - mn >= 2 || mn % 2 == here % 2){ 
            // cerr << "xd " << ans << " " << mn << " " << mx << "\n";
            cout << odd + 2 * ans << "\n"; 
            return;
        }
    }
    cout << odd << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}   