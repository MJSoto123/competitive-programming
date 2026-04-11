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

void solve(){
    int n, m; cin >> n >> m;
    vvi a(n, vi(m));
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, m) a[i][j] = (s[j] == '#');
    }

    auto get = [&](vi need, vi have){
        int cnt = 0;
        rep(i, 0, m){
            if(need[i] && !have[i]) return -1;
            if(!need[i] && have[i]) cnt++;
        }
        return cnt;
    };

    auto check = [&](vi need, vi have){
        rep(i, 0, m - 1){
            if(need[i] && need[i + 1] && have[i] && have[i + 1]) return false;
        }
        return true;
    };

    auto bin = [&](int mask){
        vi state(m, 0);
        rep(i, 0, m) state[i] = ((mask & (1 << i)) ? 1 : 0);
        return state;
    };

    vi dp(1 << m);
    rep(i, 0, n){
        vi ndp(1 << m, 100);
        rep(mask, 0, (1 << m)){
            vi st = bin(mask);
            int cost = get(st, a[i]);
            if(cost == -1) continue;

            rep(lst, 0, (1 << m)){
                vi st2 = bin(lst);
                bool ok = check(st, st2);
                if(i == 0) ok = check(st, vi(m, 0));
                if(ok){
                    ndp[mask] = min(ndp[mask], dp[lst] + cost);
                }
            }
        }
        swap(dp, ndp);
    }

    int ans = 100;
    rep(mask, 0, (1 << m)) ans = min(ans, dp[mask]);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}