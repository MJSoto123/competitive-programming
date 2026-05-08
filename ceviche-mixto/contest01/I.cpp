#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;



template<class T> int sgn(T x) { return (x > 0) - (x < 0) ; }
template<class T> 
struct Point { 
    typedef Point P ; 
    T x, y; 
    explicit Point(T x = 0, T y = 0) : x(x), y(y) { }
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y) ;}
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt(double(dist2())); }
    P unit() const { return *this/dist(); }
    P perp() const { return P(-y, x); }
    double angle() const { return  atan2(y, x); }

    friend ostream& operator<<(ostream& os, P p) { 
        return os << "(" << p.x << "," << p.y << ")";
    }
};

using D = long double ; 
using P = Point<ll> ; 
using pt = Point<D> ;
const D pi = acos(-1); 

vector<P> hull(vector<P> pts) { 
    if(sz(pts) <= 1) return pts; 
    sort(all(pts)); 
    vector<P> h(sz(pts) + 1) ; 
    int s = 0, t = 0; 
    for(int it = 2; it--; s = --t, reverse(all(pts))) 
        for(P p : pts) { 
            while(t >= s +  2 && h[t - 2].cross(h[t - 1], p) <= 0) t--; 
            h[t++] = p; 
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])}; 
}

D lineDist(const pt& a, const pt& b, const pt& p) { 
    return (D)(b - a).cross(p - a)/(b-a).dist(); 
}   

vector<pt> circleLine(pt c, D r, pt a, pt b) { 
    pt ab = b - a, p = a + ab * (c - a).dot(ab) / ab.dist2(); 
    D s = a.cross(b, c), h2 = r * r - s * s / ab.dist2(); 
    if(h2 < 0) return { };
    if(h2 == 0) return {p}; 
    pt h = ab.unit() * sqrt(h2); 
    return {p - h, p + h}; 
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n; 
    D r; cin >> r; 
    cout << fixed << setprecision(12) ; 

    vector<P> pts(n); 
    rep(i,0,n) { 
        int x, y; cin >> x >> y; 
        pts[i].x = x;
        pts[i].y = y; 
    }

    if(n == 1) { 
        cout << pi * r * r / 2.0 << "\n"; return 0;
    }

    pt z(0,0); 
    auto ch = hull(pts); 
    
    // cerr << "ch: " ; 
    // for(auto p : ch) cerr << p << "\n"; 
    D ans = 0; 
    
    auto test = [&](D dist) -> D { 
        pt aux = z + pt(dist, 0); 
        pt top = aux + pt(0,1); 
        pt bot = aux - pt(0,1); 
        auto inter = circleLine(z, r, top, bot); 
        assert(sz(inter) == 2); 
        D angle = abs(inter[0].angle() - inter[1].angle()); 
        angle = min(angle, 2 * pi - angle); 
        D area1 = angle * r * r / 2.0; 
        D triangulo = dist * (inter[0] - inter[1]).dist() / 2.0; 
        D area2 = area1 - triangulo, circ = pi * r * r; 
        return min(area2, circ - area2);
    };

    rep(i,0,sz(ch)) { 
        int j = (i + 1 == sz(ch) ? 0 : i + 1);
        pt p1, p2; 
        p1.x = ch[i].x; p1.y = ch[i].y; 
        p2.x = ch[j].x; p2.y = ch[j].y; 
        D dist = abs(lineDist(p1,p2,z));
        ans = max(ans, test(dist)); 
        ans = max(ans, D(ch[i].dist())); 

    }

    bool inside = true; 
    rep(i,0,sz(ch)) { 
        int j = (i + 1 == sz(ch) ? 0 : i + 1);
        P p1 = ch[i], p2 = ch[j]; 
        if(p1.cross(p2, P(0,0)) <= 0) inside = false; 
    }
    // cerr << "inside: " << inside << "\n"; 
    if(!inside) { 
        ans = max(ans, pi * r * r / 2.0) ; 
    }

    cout << ans << "\n"; 
    // cerr << "min_dist: " << min_dist << "\n";
    
    

    // cerr << "inters: " ; 
    // for(auto p : inter) cerr << p << "\n"; 


    // // cerr << "angle: " << angle << "\n"; 
    // // cerr << "a1, a2: " << inter[0].angle() << " " << inter[1].angle() << "\n"; 
    // // cerr << "area1: " << area1 << "\n"; 
    // // cerr << "triang: " << triangulo << "\n"; 

}