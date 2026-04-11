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

    int n, q; cin >> n >> q;
    vl a(n); 
    for(int i = 0; i < n; i++) cin >> a[i];

    int sq = sqrt(n) + 1;
    vl change((n + sq - 1) / sq);
    vl add((n + sq - 1) / sq);
    vl sm((n + sq - 1) / sq);

    for(int i = 0; i < n; i++) sm[i / sq] += a[i];

    auto fix = [&](int id){
        int l = id * sq, r = min((id + 1) * sq - 1, n - 1);
        if(change[id] != 0){
            for(int i = l; i <= r; i++) a[i] = change[id];
            change[id] = 0;
        }
        if(add[id] != 0){
            for(int i = l; i <= r; i++) a[i] += add[id];
            add[id] = 0;
        }

        sm[id] = 0;
        for(int i = l; i <= r; i++) sm[id] += a[i];
    };

    for(int qq = 0; qq < q; qq++){
        int op, l, r; cin >> op >> l >> r;
        l--; r--;
        int idl = l / sq, idr = r / sq;

        if(op == 1){
            int x; cin >> x;
            if(idl == idr){
                fix(idl);
                for(int i = l; i <= r; i++) a[i] += x, sm[idl] += x;
            }
            else{
                fix(idl);
                fix(idr);
                for(int i = l; i < (idl + 1) * sq; i++) a[i] += x, sm[idl] += x;
                for(int i = idl + 1; i < idr; i++) add[i] += x, sm[i] += x * sq;
                for(int i = idr * sq; i <= r; i++) a[i] += x, sm[idr] += x; 
            }
        }else if(op == 2){
            int k; cin >> k;
            if(idl == idr){
                fix(idl);
                for(int i = l; i <= r; i++) sm[idl] += k - a[i], a[i] = k;
            }else{
                fix(idl);
                fix(idr);
                for(int i = l; i < (idl + 1) * sq; i++) sm[idl] += k - a[i], a[i] = k;
                for(int i = idl + 1; i < idr; i++) change[i] = k, add[i] = 0, sm[i] = k * sq;;
                for(int i = idr * sq; i <= r; i++) sm[idr] += k - a[i], a[i] = k;
            }
        }else{
            ll ans = 0;
            if(idl == idr){
                fix(idl);
                for(int i = l; i <= r; i++) ans += a[i];
            }else{
                fix(idl);
                fix(idr);
                for(int i = l; i < (idl + 1) * sq; i++) ans += a[i];
                for(int i = idl + 1; i < idr; i++) ans += sm[i];
                for(int i = idr * sq; i <= r; i++) ans += a[i];
            }

            cout << ans << "\n";
        }
    }
}