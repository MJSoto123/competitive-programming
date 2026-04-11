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
    vector<string> names(n);
    vi a(n);
    for(int i = 0; i < n; i++) cin >> names[i] >> a[i];
    vi mn(n), mx(n);

    // nuevo repertorio de chistes xd
    bool ok = true;
    for(int i = 0; i < n; i++){
        mn[i] = max(0, a[i] * 100 - 50);
        mx[i] = min(10000, a[i] * 100 + 49);
    }

    int mnsum = accumulate(mn.begin(), mn.end(), 0);
    int mxsum = accumulate(mx.begin(), mx.end(), 0);
    for(int i = 0; i < n; i++){
        mn[i] = max(mn[i], 10000 - (mxsum - mx[i]));
        if(mn[i] > mx[i]) ok = false;
    }
    
    for(int i = 0; i < n; i++){
        mx[i] = min(mx[i], 10000 - (mnsum - mn[i]));
        if(mn[i] > mx[i]) ok = false;
    }
    
    if(!ok){ cout << "IMPOSSIBLE\n"; return 0; }
    cout << fixed << setprecision(2);
    for(int i = 0; i < n; i++){
        cout << names[i] << " " << mn[i] * 1.0 / 100.0 << " " << mx[i] * 1.0 / 100.0 << "\n";
    }
}