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
    vector<pii> l(n);
    vector<pii> r(n);

    for(int i = 0; i < n; i++){
        cin >> l[i].first >> l[i].second;
        cin >> r[i].first >> r[i].second;
    }

    
    int inf = 1e9 + 10;
    pii bad = {inf, -inf};
    auto inter = [&](int l1, int r1, int l2, int r2){
        if(l1 > r2 || l2 > r1) return bad;;
        return make_pair(max(l1, l2), min(r1, r2));
    };
    
    pii NIL(-inf, inf);
    vector<pii> preh(n + 1);
    vector<pii> prev(n + 1);
    preh[0] = NIL;
    prev[0] = NIL;

    for(int i = 0; i < n; i++) preh[i + 1] = inter(preh[i].first , preh[i].second, l[i].first, r[i].first);
    
    for(int i = 0; i < n; i++) prev[i + 1] = inter(prev[i].first , prev[i].second, l[i].second, r[i].second);

    vector<pii> sufh(n + 1);
    vector<pii> sufv(n + 1);
    sufh[n] = NIL;
    sufv[n] = NIL;

    for(int i = n - 1; i >= 0; i--) sufh[i] = inter(sufh[i + 1].first , sufh[i + 1].second, l[i].first, r[i].first);
    
    for(int i = n - 1; i >= 0; i--) sufv[i] = inter(sufv[i + 1].first , sufv[i + 1].second, l[i].second, r[i].second);

    for(int i = 0; i < n; i++){
        pii h = inter(preh[i].first, preh[i].second, sufh[i + 1].first, sufh[i + 1].second);

        pii v = inter(prev[i].first, prev[i].second, sufv[i + 1].first, sufv[i + 1].second);

        if(h == bad || v == bad) continue;
        cout << h.first << " " << v.first << "\n";
        return 0;
    }
}