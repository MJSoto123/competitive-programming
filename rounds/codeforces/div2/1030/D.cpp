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
    ll n, k; cin >> n >> k;
    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vi b(n); 
    for(int i = 0; i < n; i++) cin >> b[i];

    function<bool(ll)> go = [&](ll pos){
        int add = 1;
        auto nxt = lower_bound(a.begin(), a.end(), pos);
        if(nxt == a.end()) return true;
        ll time = *nxt - pos;
        pos = *nxt;
        int ii = nxt - a.begin();
        vector<vvi> vis(n, vvi(k, vi(2)));

        int steps = 0;
        while(steps < n * k * 2 + 100){
            if(vis[ii][time % k][add]) return false;
            vis[ii][time % k][add] = 1;

            if(b[ii] == time % k) add ^= 1;
            if(add == 1){
                if(ii == n - 1) return true;
                time += abs(a[ii + 1] - a[ii]);
                pos = a[ii + 1];
                ii++;
            }else{
                if(ii == 0) return true;
                time += abs(a[ii] - a[ii - 1]);
                pos = a[ii - 1];
                ii--;
            }
            steps++;
        }
        return false;
    };

    int q; cin >> q;
    for(int qq = 0; qq < q; qq++){
        int pos; cin >> pos;
        if(go(pos)) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}