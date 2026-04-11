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
    int n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            cnt++;
            if(cnt == k){
                i++;
                cnt = 0;
                ans++;
            }
        }else cnt = 0;
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}