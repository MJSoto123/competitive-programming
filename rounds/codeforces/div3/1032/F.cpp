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
    ll n, s, k; cin >> n >> s >> k;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vvi b;
    int mx = -1e9 - 1;
    vi now;    
    for(int i = 0; i < n; i++){
        if(a[i] > k){
            if(mx == k && now.size()) b.emplace_back(now);
            mx = -1e9 - 1;
            now.clear();
        }else{
            now.emplace_back(a[i]);
            mx = max(mx, a[i]);
        }
    }
    if(mx == k && now.size()) b.emplace_back(now);

    ll ans = 0;
    for(auto vec : b){
        set<int> st;
        for(int i = 0; i < vec.size(); i++) if(vec[i] == k) st.insert(i);

        map<ll, vi> mp;
        ll acum = 0;
        for(int i = 0; i < vec.size(); i++){
            acum += vec[i];
            mp[acum].emplace_back(i);
        }

        acum = 0;
        for(int i = 0; i < vec.size(); i++){
            acum += vec[i];
            auto it = st.lower_bound(i);
            if(it == st.end()) continue;
            int fpos = *it;
            ll target = s + acum - vec[i];
            
            if(!mp.count(target)) continue;
            auto ot = lower_bound(mp[target].begin(), mp[target].end(), fpos);
            
            if(ot == mp[target].end()) continue;
            ans += mp[target].end() - ot;
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tt; cin >> tt;
    while(tt--) solve();
}