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

    int sq = sqrt(n) + q;
    vector<unordered_map<int, int>> b((n + sq - 1) / sq);
    for(int i = 0; i < n; i++) b[i / sq][a[i]]++;

    for(int qq = 0; qq < q; qq++){
        int op; cin >> op;
        if(op == 1){
            int l, r, k; cin >> l >> r >> k;
            r--;
            int idl = l / sq, idr = r / sq;
            int ans = 0;
            if(idl == idr){
                for(int i = l; i <= r; i++) if(a[i] == k) ans++;
            }else{
                for(int i = l; i < (idl + 1) * sq; i++) if(a[i] == k) ans++;
                for(int i = idl + 1; i < idr; i++) if(b[i].count(k)) ans += b[i][k];
                for(int i = idr * sq; i <= r; i++) if(a[i] == k) ans++;
            }
            cout << ans << "\n";
        }else{
            int pos, k; cin >> pos >> k;
            int id = pos / sq;
            int now = a[pos];
            
            b[id][now]--;
            if(b[id][now] == 0) b[id].erase(now);
            b[id][k]++;

            a[pos] = k;
        }
    }
}