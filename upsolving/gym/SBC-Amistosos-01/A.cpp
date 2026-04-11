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

    vvi g(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            g[i][j] = gcd(a[i], a[j]);
        }
    }

    vvi dpr(n, vi(n, 0));
    vvi dpl(n, vi(n, 0));
    for(int i = 0; i < n; i++) dpl[i][i] = 1;
    for(int i = 0; i < n; i++) dpr[i][i] = 1;

    for(int k = 2; k <= n; k++){
        for(int l = 0; l < n; l++){
            int r = l + k - 1;
            if(r >= n) continue;
            for(int i = l; i <= r; i++){
                bool ok = true;
                if(i - 1 >= l) ok &= dpl[l][i - 1];
                if(i + 1 <= r) ok &= dpr[i + 1][r];
                if(!ok) continue;

                if(l - 1 >= 0 && g[l - 1][i] > 1) dpl[l][r] = 1;
                if(r + 1 < n && g[i][r + 1] > 1) dpr[l][r] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        bool ok = true;
        if(i - 1 >= 0) ok &= dpl[0][i - 1];
        if(i + 1 <= n - 1) ok &= dpr[i + 1][n - 1];
        if(!ok) continue;
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
}