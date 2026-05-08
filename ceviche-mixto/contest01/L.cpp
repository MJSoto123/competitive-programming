#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;

const ll INF = 1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    vector<pll> ga;
    for (ll i = 0; i+1 < n; ++i) {
        if (s[i] == s[i+1]) {
            if (i+k < n) {
                ga.emplace_back(0, 1);
            } else {
                ga.emplace_back(0,0);
            }
        } else {
            if (i+k < n) {
                ga.emplace_back(1, 1);
            } else {
                ga.emplace_back(1,0);
            }
        }
    }

    vector<vector<pll>> info(k);

    for (ll i = 0; i < n-1; ++i) {
        ll group = i%k;
        info[group].push_back(ga[i]);
    }

    // cout << "Grupos:" << endl;
    // for (auto ee : info) {
    //     for (auto [val, mov] : ee) cout << val << " ";
    //     cout << endl;
    //     for (auto [val, mov] : ee) cout << mov << " ";
    //     cout << endl;
    // }

    vector<vector<ll>> dps(k);
    for (ll i = 0; i < k; ++i) {
        // 0: no fue cambiado, 1: fue cambiado
        ll len = 1 + sz(info[i]);
        vector<vl> dp(2, vl(len, -INF));
        dp[0][0] = 0;
        dp[1][0] = -INF;
        dp[1][1] = 0;

        if (i != k-1) {
            dp[1][1] = -INF;
        }

        for (auto [val, mov] : info[i]) {
            vector<vl> dp2(2, vl(len, -INF));

            // no cambiado
            for (ll j = 0; j < len; ++j) {
                // cambio este
                if (mov==1 && j+1<len) {
                    dp2[1][j+1] = max(dp2[1][j+1], dp[0][j] + (val==1 ? 0 : 1));
                }
                // no cambio este
                dp2[0][j] = max(dp2[0][j], dp[0][j] + (val==1 ? 1 : 0));
            }

            // cambiado
            for (ll j = 0; j < len; ++j) {
                // cambio este
                if (mov==1 && j+1<len) {
                    dp2[1][j+1] = max(dp2[1][j+1], dp[1][j] + (val==1 ? 1 : 0));
                }
                // no cambio este
                dp2[0][j] = max(dp2[0][j], dp[1][j] + (val==1 ? 0 : 1));
            }

            swap(dp, dp2);
        }

        dps[i] = dp[0];
        for (ll j = 0; j < len; ++j) dps[i][j] = max(dps[i][j], dp[1][j]);
    }

    
    // cout << "dp:" << endl;
    // for (auto e : dps) {
    //     for (auto ee : e) cerr << ee << " ";
    //     cerr << endl;
    // }

    set<pll> se;
    for (ll i = 0; i < k; ++i) {
        se.emplace(sz(dps[i]), i);
    }

    while (sz(se) >= 2) {
        auto [len1, ind1] = *se.begin();
        se.erase(se.begin());
        auto [len2, ind2] = *se.begin();
        se.erase(se.begin());

        vl re(len1+len2-1, 0);

        // proceso :V
        for (ll i = 0; i < len1; ++i) {
            for (ll j = 0; j < len2; ++j) {
                re[i+j] = max(re[i+j], dps[ind1][i] + dps[ind2][j]);
            }
        }

        // cout << "re: ";
        // for (auto e : re) {
        //     cout <<  e << " ";
        // }
        // cout << endl;
        dps[ind1] = re;
        se.emplace(len1+len2-1, ind1);
    }

    auto [len, ind] = *se.begin();
    ll response = 0;
    for (ll i = 0; i <= min(m, len-1); ++i) {
        // cout << "i: " << i << " " << dps[ind][i] <<  endl;
        response = max(response, dps[ind][i]);
    }

    response++;
    cout << response << "\n";
}

