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
    int a, b, x, y; cin >> a >> b >> x >> y;
    if(a == b){ cout << "0\n"; return; }
    if(a > b){
        if((a ^ 1) != b) cout << "-1\n";
        else cout << y << "\n";
        return;
    }

    int ans = 0;
    int add = min(x, y);
    for(int i = a; i < b; i++){
        if(i % 2 == 0) ans += add;
        else ans += x;
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}