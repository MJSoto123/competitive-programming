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
typedef long double ld;

ld dist(ld x1, ld y1, ld x2, ld y2){
    ld dx = (x2 - x1);
    ld dy = (y2 - y1);
    return sqrtl(dx * dx + dy * dy);
}

void solve(){
    ld x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ld v, t; cin >> v >> t;
    ld vx, vy; cin >> vx >> vy;
    ld wx, wy; cin >> wx >> wy;

    auto f = [&](ld tot){
        ld t1 = min(tot, t);
        ld t2 = tot - t1;

        ld nx = x1 + (t1 * vx) + (t2 * wx);
        ld ny = y1 + (t1 * vy) + (t2 * wy);

        return (dist(nx, ny, x2, y2) <= v * tot);
    };

    ld l = 0, r = 1e18;
    rep(i, 0, 100){
        ld mid = (l + r) / 2.0;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(7);
    solve();
}