#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    int n, m; cin >> n >> m;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi b(m), c(m);
    rep(i, 0, m) cin >> b[i];
    rep(i, 0, m) cin >> c[i];

    vii good, bad;
    rep(i, 0, m){
        if(c[i] == 0) bad.emplace_back(b[i], c[i]);
        else good.emplace_back(b[i], c[i]);
    }

    sort(all(good));
    reverse(all(good));

    sort(all(bad));
    sort(all(a));

    int best = a.back();
    multiset<int> alive;
    for(auto x : a) alive.emplace(x);
    int ans = 0;

    priority_queue<pii, vii, greater<pii>> q;
    auto fix = [&](){
        while(sz(good) && good.back().first <= best){
            auto [bi, ci] = good.back();
            q.emplace(ci, bi);
            good.pop_back();
        }
    };

    fix();
    while(sz(q)){
        auto [ci, bi] = q.top(); q.pop();
        auto it = alive.lower_bound(bi);
        int here = *it;
        alive.erase(it);

        alive.emplace(max(here, ci));
        best = max(best, ci);
        ans++;
        fix();
    }

    for(auto [bi, _] : bad){
        auto it = alive.lower_bound(bi);
        if(it == alive.end()) break;
        ans++;
        alive.erase(it);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}