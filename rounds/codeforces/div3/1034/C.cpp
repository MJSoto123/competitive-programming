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
    
    vi mx(n);
    vi mn(n);
    mx[n - 1] = a[n - 1];
    mn[0] = a[0];

    for(int i = 1; i < n; i++) mn[i] = min(mn[i - 1], a[i]);
    for(int i = n - 2; i >= 0; i--) mx[i] = max(mx[i + 1], a[i]);
    
    // for(auto x : mn) cout << x << " ";
    // cout << "\n";

    // for(auto x : mx) cout << x << " ";
    // cout << "\n";

    map<int, int> mp;
    for(int i = 0; i < n; i++) mp[a[i]] = i;

    string s(n, '0');
    int mnnow = *min_element(a.begin(), a.end());
    int mxnow = *max_element(a.begin(), a.end());
    s[mp[mnnow]] = '1';
    s[mp[mxnow]] = '1';

    for(int i = 0; i < n; i++){
        if(mx[i] == a[i] || mn[i] == a[i]) s[i] = '1';
    }

    cout << s << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}