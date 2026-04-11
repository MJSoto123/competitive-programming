#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define vd vector<double>
#define vvd vector<vd>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }



template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
    friend istream& operator>>(istream& os, P p) {
		return os >> p.x >> p.y; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}


template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<Point<int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<Point<int>> l(m), r(m);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    auto check = [&](int u, int v){
        return true;
    };

    vvd g(n, vd(n, 1e12));
    for(int u = 0; u < n; u++){
        for(int v = 0; v < n; v++){
            if(check(u, v)){
                g[u][v] = min(g[u][v], ((a[u] - a[v]).dist()));
                g[v][u] = min(g[u][v], ((a[u] - a[v]).dist()));
            }
        }
    }
    
    int k; cin >> k;
    vi b(k);
    for(int i = 0; i < k; i++) cin >> b[i], b[i]--;
    vi good(n);
    for(auto x : b) good[x] = 1;

    vvd dp((1 << k), vd(n, 1e12));
    for(int i = 0; i < k; i++) dp[(1 << i)][b[i]] = 0;

    for(int mask = 0; mask < (1 << k); mask++){
        for(int u = 0; u < n; u++){
            int nmask = mask;
            if(good[u]) nmask = mask ^ (1 << u);

            for(int v = 0; v < n; v++){
                if(u == v) continue;
                if(g[u][v] == 1e12) continue;
                dp[mask][u] = min(dp[mask][u], dp[nmask][v] + g[u][v]);
            }
        }
    }

    double ans = 1e12;
    for(int u = 0; u < n; u++) ans = min(ans, dp[(1 << k) - 1][u]);

    if(ans == 1e12) cout << "impossible\n";
    else cout << ans << "\n";
}