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
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];   
    for(int i = 0; i < n; i++) cin >> b[i];   

    if(b.back() != a.back()){ cout << "NO\n"; return; }
    for(int i = n - 2; i >= 0; i--){
        if((a[i] == b[i]) || (a[i] ^ b[i + 1]) == b[i] || (a[i] ^ a[i + 1]) == b[i]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}