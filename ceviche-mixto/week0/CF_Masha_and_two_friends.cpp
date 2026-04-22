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

// white 1
int col(int x, int y){ return x % 2 == y % 2; }
struct Rect{
    ll xl, yl, xr, yr;
    Rect(ll x1, ll y1, ll x2, ll y2){
        xl = min(x1, x2);
        yl = min(y1, y2);
        xr = max(x1, x2);
        yr = max(y1, y2);
    }

    bool inter(Rect o){
        return !(o.xr < xl || xr < o.xl || o.yr < yl || yr < o.yl);
    }

    Rect get(Rect o){
        Rect ret(0, 0, 0, 0);
        ret.xl = max(xl, o.xl);
        ret.xr = min(xr, o.xr);
        ret.yl = max(yl, o.yl);
        ret.yr = min(yr, o.yr);

        return ret;
    }

    ll area(){ return (xr - xl + 1) * (yr - yl + 1); }
    
    pair<ll, ll> colors(){
        ll s = area();

        pair<ll, ll> ret = { s / 2, s / 2 };
        if(s % 2){
            if(col(xl, yl)) ret.first++;
            else ret.second++;
        }
        return ret;
    }
};

void solve(){
    ll n, m; cin >> n >> m;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
    Rect a(x1, y1, x2, y2), b(x3, y3, x4, y4);

    ll tot = n * m;
    ll white = (tot + 1) / 2;
    ll black = tot / 2;

    // blanco
    {
        auto [ww, bb] = a.colors();
        white -= ww;
        black -= bb;
        white += a.area();
    }
    
    // negro
    {
        auto [ww, bb] = b.colors();
        white -= ww;
        black -= bb;
        black += b.area();
    }
    
    // quitar doble
    if(a.inter(b)){
        Rect c = a.get(b);
        auto [ww, bb] = c.colors();
        white += ww;
        black += bb;
        white -= c.area();
    }

    cout << white << " " << black << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}