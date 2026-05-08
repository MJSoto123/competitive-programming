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

    ll w, h, d;
    cin >> w >> h >> d;
    ll n;
    cin >> n;

    vector<vl> div(3);

    auto ga = [&](ll x, ll ind) -> void {
        vl tmp;
        for (ll i = 1; i*i <= x; ++i) {
            if(x % i == 0) {
                if (i == x/i) {
                    div[ind].push_back(i);
                } else {
                    div[ind].push_back(i);
                    tmp.push_back(x / i);
                }
                
            }
        }    
        while (!tmp.empty()) {
            div[ind].push_back(tmp.back());
            tmp.pop_back();
        }
    };

    ga(w, 0);
    ga(h, 1);
    ga(d, 2);

    set<ll> se;
    for (auto e : div[2]) se.insert(e);

    for (auto e : div[0]) {
        for (auto ee : div[1]) {
            ll ga = e*ee;
            if (n % ga == 0) {
                ll ga2 = n / ga;
                if (se.count(ga2)) {
                    cout << e-1 << " " << ee-1 << " " << ga2-1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << -1 << "\n";
}