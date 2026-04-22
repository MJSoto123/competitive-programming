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

template<class T>
struct Point{
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
};

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts){
    if(sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<P> h(sz(pts) + 1);
    int s = 0, t = 0;
    for(int it = 2; it--; s = --t, reverse(all(pts)))
        for(P p : pts){
            while(t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;
            h[t++] = p;
        }

    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}
void solve(){
    int n; cin >> n;

    vector<P> p(n);
    map<P, int> mp;
    rep(i, 0, n){
        cin >> p[i].x >> p[i].y;
        if(!mp.count(p[i])) mp[p[i]] = i;
    }

    auto hull = convexHull(p);
    int n2 = sz(hull);
    P fs(10000, 10000);
    int id; 

    rep(i, 0, n2){
        if(fs.y > hull[i].y) fs = hull[i], id = i;
        if(fs.y == hull[i].y && fs.x > hull[i].x) fs = hull[i], id = i;
    }
    rotate(hull.begin(), hull.begin() + id, hull.end());

    long double d = 0;
    rep(i, 0, n2) d += (hull[i] - hull[(i + n2 - 1) % n2]).dist();

    cout << d << "\n";
    rep(i, 0, n2) cout << mp[hull[i]] + 1 << " "; cout << "\n";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(2);
    int tt; cin >> tt;
    while(tt--) solve();
}