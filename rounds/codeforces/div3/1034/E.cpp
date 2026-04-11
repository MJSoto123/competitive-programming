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

    vi mp(n + 2);
    for(int i = 0; i < n; i++) mp[a[i]]++;

    int mex = -1;
    for(int i = 0; i <= n + 1; i++) if(mp[i] == 0){mex = i; break;}

    vi ans(n + 2, 0);
    for(int i = 0; i <= mex; i++){
        int low = mp[i];
        int high = n - i;
        if(low > high) continue;
        ans[low] += 1;
        ans[high + 1] -= 1; 
    }

    for(int i = 1; i <= n; i++) ans[i] += ans[i - 1];
    for(int i = 0; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}