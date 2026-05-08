#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(7);

    int n; cin >> n;
    vii pts(n);
    rep(i, 0, n){
        int x, y; cin >> x >> y;
        int g = __gcd(abs(x), abs(y));
        x /= g;
        y /= g;
        pts[i] = {x, y};
    }

    sort(all(pts));
    pts.erase(unique(all(pts)), pts.end());

    n = sz(pts);
    if(n == 1){ cout << 0.0 << "\n"; return 0; }

    vector<double> ang(n);
    rep(i, 0, n) ang[i] = atan2(pts[i].second, pts[i].first);

    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int l, int r){
        return ang[l] < ang[r];
    });

    double pi = acos(-1);
    double ans = pi * 2;
    rep(i, 0, n){
        double a1 = ang[ord[i]];
        double a2 = ang[ord[(i + 1) % n]];
        
        double gap = a2 - a1;
        if(a1 > a2) gap = pi * 2 - a1 + a2;
        ans = min(ans, 2 * acos(-1) - gap);
    }

    cout << ans / pi * 180 << "\n";
}