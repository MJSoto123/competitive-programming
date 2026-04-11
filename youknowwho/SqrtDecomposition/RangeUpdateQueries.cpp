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
    vl b((n + sq - 1)/ sq);
    
    for(int qq = 0; qq < q; qq++){
        int op; cin >> op;
        if(op == 1){
            int l, r, add; cin >> l >> r >> add;
            l--; r--;
            int idl = l / sq, idr = r / sq;
            if(idl == idr){
                for(int i = l; i <= r; i++) a[i] += add;
            }else{
                for(int i = l; i < (idl + 1) * sq; i++) a[i] += add;
                for(int i = idl + 1; i < idr; i++) b[i] += add;
                for(int i = idr * sq; i <= r; i++) a[i] += add;
            }
        }else{
            int pos; cin >> pos;
            pos--;
            cout << a[pos] + b[pos / sq] << "\n";
        }
    }
}