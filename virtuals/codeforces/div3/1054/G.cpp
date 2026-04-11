#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pii = pair<int,int>;
using vii = vector<pii>;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi d = a;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();

    vvi mp(n);
    rep(i, 0, n) mp[a[i]].emplace_back(i);
    
    rep(qq, 0, q){
        int l, r; cin >> l >> r; r--; l--;
        
        set<int> ans;
        uniform_int_distribution<int> dist(l, r);
        rep(i, 0, 210){
            int rand = dist(rng);
            // siempre esta
            int posl = lower_bound(all(mp[a[rand]]), l) - mp[a[rand]].begin();
            int posr = lower_bound(all(mp[a[rand]]), r + 1) - mp[a[rand]].begin();
            int have = posr - posl;
            if(have > (r - l + 1) / 3) ans.insert(d[a[rand]]);
        }
        
        if(!sz(ans)) cout << "-1\n";
        else{
            for(auto x : ans) cout << x << " "; cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}
