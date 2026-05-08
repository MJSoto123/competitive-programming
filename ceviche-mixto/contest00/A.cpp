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

    ll n, m; cin >> n >> m;
    vector<vl> cnt(n, vl(30, 0));
    vl sm(30);

    rep(i, 0, n){
        string s; cin >> s;
        for(auto c : s){
            int id = c - 'A';
            cnt[i][id]++;
            sm[id]++;
        }
    }

    rep(i, 0, n){
        bool bad = 0;
        vl disp(26);
        rep(c, 0, 26) disp[c] = m * (sm[c] - cnt[i][c]) - cnt[i][c];

        rep(c, 0, 26) if(disp[c] < 0) bad = 1;
        if(bad){ cout << "-1 "; continue; }

        vl need(26);
        rep(c, 0, 26) need[c] = sm[c] - cnt[i][c];

        ll ans = 1e18;
        rep(c, 0, 26){
            if(need[c] == 0) continue;
            ans = min(ans, disp[c] / need[c]);
        }

        cout << ans << " ";
    }
    cout << "\n";
}