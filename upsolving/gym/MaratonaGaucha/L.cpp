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
    sort(a.begin(), a.end());

    if(a[n - 1] != a[n - 2]){ cout << a[n - 1] << "\n"; return 0; }
    int target = a[n - 1] + 1;

    int best = a[n - 1] + a[0];
    multiset<int> ms;
    for(int i = 0; i < n; i++){
        int need = target - a[i];
        auto it = ms.lower_bound(need);
        if(it != ms.end()) best = min(best, *it + a[i]);
        ms.insert(a[i]);
    }

    cout << best << "\n";
}