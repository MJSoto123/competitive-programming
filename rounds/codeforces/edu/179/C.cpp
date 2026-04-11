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
    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    if(count(a.begin(), a.end(), a[0]) == n) {cout << "0\n"; return;}

    long long ans = 1e18;
    long long pos = 0;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]){
            long long now = 1LL * a[pos] * (pos) + 1LL * a[pos] * (n - (i));
            ans = min(ans, now);
            pos = i;
        }
    }

    long long now = 1LL * a[pos] * (pos) - 1LL * a[pos] * (n - (n - 1 + 1));
    ans = min(ans, now);

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}