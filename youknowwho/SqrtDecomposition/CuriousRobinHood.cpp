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

void solve(){
    int n, q; cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int sq = sqrt(n) + 1;
    vi b((n + sq - 1) / sq);
    for(int i = 0; i < n; i++) b[i / sq] += a[i];

    for(int qq = 0; qq < q; qq++){
        int op; cin >> op;
        if(op == 1){
            int pos; cin >> pos;
            int id = pos / sq;
            cout << a[pos] << "\n";
            b[id] -= a[pos];
            a[pos] = 0;
        }else if(op == 2){
            int pos, add; cin >> pos >> add;
            int id = pos / sq;
            b[id] += add;
            a[pos] += add;
        }else{
            int l, r; cin >> l >> r;
            int idl = l / sq, idr = r / sq;
            ll ans = 0;
            if(idl == idr){
                for(int i = l; i <= r; i++) ans += a[i];
            }else{
                for(int i = l; i < (idl + 1) * sq; i++) ans += a[i];
                for(int i = idl + 1; i < idr; i++) ans += b[i];
                for(int i = idr * sq; i <= r; i++) ans += a[i];
            }
            cout << ans << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    for(int i = 0; i < tt; i++){
        cout << "Case " << i + 1 << ":\n";
        solve();
    }
}