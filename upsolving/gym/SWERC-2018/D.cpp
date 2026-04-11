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

    int bigx, bigy; cin >> bigx >> bigy;
    int n; cin >> n;
    vi mx(bigx, -1), mn(bigx, 2e5);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        mx[x] = max(mx[x], y);
        mn[x] = min(mn[x], y);
    }

    vi alive; 
    for(int i = 0; i < bigx; i++){
        if(mx[i] == -1) continue;
        alive.emplace_back(mx[i]);
        alive.emplace_back(mn[i]);
    }

    sort(alive.begin(), alive.end());
    int med = alive[alive.size() / 2];

    ll ans = bigx - 1;
    // cout << "med " << med << "\n";
    for(int i = 0; i < bigx; i++){
        if(mx[i] == -1) continue;
        ans += 2 * abs(mx[i] - mn[i]);
        if(med > mx[i]) ans += 2 * (med - mx[i]);
        if(med < mn[i]) ans += 2 * (mn[i] - med);
    }

    cout << ans << "\n";
}