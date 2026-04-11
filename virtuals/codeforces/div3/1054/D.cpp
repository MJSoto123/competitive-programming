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
    string s; cin >> s;

    ll ans = 1e18;
    rep(k, 0, 2){
        vi pos;
        rep(i, 0, n) if(s[i] == 'a') pos.emplace_back(i);

        int m = sz(pos);
        if(m){
            int med = pos[m / 2];
            ll l = 0, r = 0;
            ll sml = 0, smr = 0;
            rep(i, 0, m){
                if(pos[i] < med){
                    l++;
                    sml += abs(med - pos[i]);
                }else{
                    r++;
                    smr += abs(med - pos[i]);
                }
            }
            ans = min(ans, sml + smr - (l) * (l + 1) / 2 - (r - 1) * (r) / 2);
        }
        rep(i, 0, n) s[i] = (s[i] == 'a' ? 'b' : 'a');
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}