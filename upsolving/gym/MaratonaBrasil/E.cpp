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

void solve(){
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vi dp(n);
    int now = 0;
    for(int i = 0; i < n; i++){ 
        if(a[now] == a[i]) { dp[i] = now; continue; }
        now = i;
        dp[i] = now;
    }  

    int q; cin >> q;
    for(int qq = 0; qq < q; qq++){
        int l, r; cin >> l >> r;
        l--; r--;
        if(a[l] != a[r]) { cout << l + 1 << " " << r + 1 << "\n"; continue; }

        if(dp[l] == dp[r]) cout << "-1 -1\n";
        else cout << l + 1 << " " << dp[r] << "\n";
    }

    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}