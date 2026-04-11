#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <bitset>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <climits>
#include <numeric>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <unordered_map>
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q; cin >> n >> m >> q;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    ll sma = accumulate(a.begin(), a.end(), 0LL);
    ll smb = accumulate(b.begin(), b.end(), 0LL);
    set<ll> sa, sb;
    for(auto x : a) sa.insert(sma - x);
    for(auto x : b) sb.insert(smb - x);

    bool ok = false;

    auto get = [&](ll dv1, ll dv2){
        ok = ok || sa.count(dv1) && sb.count(dv2);
    };
    
    for(int qq = 0; qq < q; qq++){
        ll x; cin >> x;
        if(x == 0) {
            cout << (sa.count(0) || sb.count(0))  ? "YES\n" : "NO\n";
            continue;
        }
        ok = false;
        for(int dv = 1; dv * dv <= abs(x); dv++){
            if(x % dv) continue;
            get(dv, x / dv);
            get(-dv, -x / dv);
            get(x / dv, dv);
            get(-x / dv, -dv);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}