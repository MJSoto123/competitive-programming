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

template<class T> int sgn(T x){ return (x > 0) - (x < 0); }
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
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<Point<ll>> pts(n);
    vi w(n);
    rep(i, 0, n) cin >> pts[i].x >> pts[i].y >> w[i];


    ll tot = accumulate(all(w), 0LL);
    ll best = 5e18;
    ll mn = 0;
    vvi vis(n, vi(n));
    rep(i, 0, n) rep(j, 0, n){
        if(vis[i][j]) continue;
        vi in, l;
        
        auto l1 = pts[i] - pts[j];
        rep(k, 0, n){
            auto l2 = pts[k] - pts[j];
            double ori = l1.cross(l2);

            if(ori == 0) in.emplace_back(k);
            else if(ori > 0) l.emplace_back(k);
        }

        sort(all(in), [&](int idl, int idr){ 
            return pts[idl] < pts[idr];
        });

        ll suml = 0;
        for(auto id : l) suml += w[id];

        ll curr = 0;
        ll other = 0;
        ll diff = 0;
        for(auto id : in){
            curr += w[id];
            other = suml + curr;
            diff = max(other, tot - other) - min(other, tot - other);
            if(best > diff){ 
                best = diff;
                mn = min(other, tot - other); 
            } else if(best == diff && mn > min(other, tot - other)){
                mn = min(other, tot - other);
            }
            
            other = suml;
            diff = max(other, tot - other) - min(other, tot - other);
            if(best > diff){ 
                best = diff;
                mn = min(other, tot - other); 
            } else if(best == diff && mn > min(other, tot - other)){
                mn = min(other, tot - other);
            }
        }
    }
    cout << mn << "\n";
}   