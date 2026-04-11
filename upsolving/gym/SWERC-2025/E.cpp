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

    int n; cin >> n;
    vii a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());

    int xmax = 0, xmin = 1e9 + 100, ymax = 0, ymin = 1e9 + 100;
    for(auto [x, y] : a){
        xmax = max(xmax, x);
        xmin = min(xmin, x);
        ymax = max(ymax, y);
        ymin = min(ymin, y);
    }

    set<int> xi, yi;
    for(auto [x, y] : a){
        xi.insert(x);
        yi.insert(y);
    }

    // col
    if(xi.size() == 1){
        cout << a.size() + 1 << "\n";
        for(auto [x, y] : a) cout << x << " " << y << "\n";
        if(a[0].first == 1) cout << 2 << " " << 1 << "\n";
        else cout << a[0].first - 1 << " " << 1 << "\n";
        return 0;
    }

    // row
    if(yi.size() == 1){
        cout << a.size() + 1 << "\n";
        for(auto [x, y] : a) cout << x << " " << y << "\n";
        if(a[0].second == 1) cout << 1 << " " << 2 << "\n";
        else cout << 1 << " " << a[0].second - 1 << "\n";
        return 0;
    }

    vii points;
    points.emplace_back(xmax, ymax);

    map<int, vi> mp;
    for(int i = n - 1; i >= 0; i--){
        auto [x, y] = a[i];
        if(y == ymax) points.emplace_back(a[i]);
        else mp[x].emplace_back(y);
    }

    if(!mp.count(xmin)) points.emplace_back(xmin, ymax - 1);

    for(auto [x, ys] : mp){
        sort(ys.rbegin(), ys.rend());
        if(x == xmax){
            if(points.size() && points.back().first == x) points.pop_back();
            if(points.size() && points.back().first != x - 1) points.emplace_back(x - 1, ymax - 1);

            reverse(ys.begin(), ys.end());
            for(auto y : ys) points.emplace_back(x, y);
            continue;
        }

        points.emplace_back(x, ymax - 1);
        for(auto y : ys) points.emplace_back(x, y);
        points.emplace_back(x + 1, ymax - 1);
    }

    vii ans;
    for(auto p : points){
        if(ans.size() && ans.back() == p) ans.pop_back();
        ans.emplace_back(p);
    }

    cout << ans.size() << "\n";
    for(auto [x, y] : ans) cout << x << " " << y << "\n";
}