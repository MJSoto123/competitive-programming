#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vl dp(k + 1, -2e10);
    vl gap(k + 1, -2e10);
    dp[0] = 0;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        vl dpnow = dp;
        vl gapnow = gap;

        for(int j = 0; j <= k; j++){
            // siempre
            dpnow[j] = max(dp[j] + a[i], a[i]);

            // solo si existe - continuar
            if(gap[j] != -2e10) gapnow[j] = max(gap[j] - a[i], - a[i]);

            // solo si existe - cerrar
            if(gap[j] != -2e10) dpnow[j] = max(dpnow[j], gap[j] + a[i]);
            
            // crearwafada
            if(j > 0) gapnow[j] = max(gapnow[j], dp[j - 1] - a[i]);
        }

        dp = dpnow;
        gap = gapnow;

        for(int j = 0; j <= k; j++){
            ans = max(ans, dp[j]);
            ans = max(ans, gap[j]);
        }
    }

    cout << ans << "\n";
}