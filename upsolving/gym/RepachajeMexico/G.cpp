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

    int g = a[0];
    for(auto x : a) g = gcd(g, x);

    for(int i = 0; i < n; i++) a[i] = a[i] / g;

    int mx = *max_element(a.begin(), a.end());
    for(int dv = 2; dv * dv <= mx; dv++){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] % dv == 0) cnt++;
        }

        if(cnt > 1){ cout << "NO\n"; return 0;}
    }
    cout << "YES\n";
}