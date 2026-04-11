#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 998244353;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

int add(ll a, ll b){ return (a + b) % MOD; }

void solve(){
    int n, m; cin >> n >> m;
    vector<set<int>> a(n + 1);
    for(int i = 0; i < m; i++){
        int x, val; cin >> x >> val;
        a[x].insert(val);
    }

    vi dp(n + 1);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        for(int w = 1; w <= n; w++){
            if(i + w > n) continue;
            for(int r = 0; r < w; r++){
                vi b(w);
                iota(b.begin(), b.end(), 1);
                rotate(b.begin(), b.begin() + r, b.end());

                bool ok = true;
                for(int pos = 0; pos < w; pos++){
                    if(a[pos + i + 1].count(b[pos])) ok = false; 
                }
                if(ok) dp[i + w] = add(dp[i + w], dp[i]);
            }
        }
    }

    cout << dp[n] << "\n";
} 

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}    