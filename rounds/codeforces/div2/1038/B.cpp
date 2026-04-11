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
    vi a(n), b(n), c(n), d(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    ll ans = 0;
    ll have = 0, need = 0;
    for(int i = 0; i < n; i++){
        if(d[i] < b[i]){
            ans = ans + (b[i] - d[i]);
            have += a[i];
            need += c[i];
        }
        else{
            if(a[i] > c[i]) have += (a[i] - c[i]);
            else need += (c[i] - a[i]);
        }
    }

    cout << ans + have << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}