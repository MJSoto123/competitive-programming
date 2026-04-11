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
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int sz = sqrt(n) + 1;
    int q; cin >> q;
    vector<pii> qq;
    for(int i = 0; i < q; i++) cin >> qq[i].first >> qq[i].second;

    sort(qq.begin(), qq.end(), [&](pii a, pii b){
        if(a.first / sz != b.first / sz) return a.first / sz < b.first / sz;
        return a.second < b.second;
    });

    int low = 0, high = -1;
    for(auto qi : qq){
        auto [l, r] = qi;
        while(high < r) add(a[]);
        while(low > l) add(a[i]);
        while(high > r) remove(a[i]);
        while(low < l) remove(a[i]);
    }
}