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

    int n, m; cin >> n >> m;
    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    vector<pair<long long, int>> dif;
    for(int i = 0; i < n - 1; i++) dif.emplace_back(a[i + 1] - a[i], i);
    
    // for(auto x : a) cout << x << " ";
    // cout << "\n";

    sort(dif.rbegin(), dif.rend());
    vi ban(n);
    for(int i = 0; i < m - 1; i++){
        // cout << dif[i].first << " " << dif[i].second << "\n";
        ban[dif[i].second] = 1;
    }

    

    ll now = a[0];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(ban[i]){
            // cout << a[i] << " " << now << " += " << a[i] - now << "\n";;
            ans += a[i] - now;
            if(i + 1 < n)  now = a[i + 1];
        }
    }
    ans += a[n - 1] - now;

    cout << ans << "\n";
}