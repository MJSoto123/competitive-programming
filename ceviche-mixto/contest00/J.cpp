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
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
using db = long double;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vl ptmp(n);
    for (auto& e : ptmp) cin >> e;
    vector<db> p(101);
    map<ll, ll> cntp;
    for (ll i = 0; i < n; ++i) {
        cntp[ptmp[i]]++;
        p[ptmp[i]] = db(ptmp[i]) / db(100);
    }

    map<pll, ll> mp;
    vector<map<pll, db>> info(101);
    vector<map<pll, db>> P(101);

    auto calc = [&](auto&& self, ll deep, ll diff, bool plus) -> void {
        if (mp.count({deep, diff})) {
            return;
        }

        if (deep == 0 && diff == 0) {
            for (auto [pro, cnt] : cntp) {
                P[pro][{deep, diff}] = db(1);
            }
        } else {
            for (auto [pro, cnt] : cntp) {
                if (plus) {
                    P[pro][{deep, diff}] = P[pro][{deep-1, diff-1}] * p[pro];
                } else {
                    P[pro][{deep, diff}] = P[pro][{deep-1, diff+1}] * (db(1)-p[pro]);
                }
            }
        }
        

        if (deep == k) {
            mp[{deep, diff}] = 0;
            for (auto [pro, cnt] : cntp) {
                info[pro][{deep, diff}] = db(1);
            }
            return;
        }

        self(self, deep+1, diff+1, true);
        self(self, deep+1, diff-1, false);

        // good - bad = diff
        // good + bad = deep
        ll good = (deep + diff) / 2;
        ll bad = deep - good;

        // veo si se apuesta todo o nada
        db total = 0;
        
        for (auto [pro, cnt] : cntp) {
            db PP = P[pro][{deep, diff}];
            db cp = info[pro][{deep+1, diff+1}];
            db cm = info[pro][{deep+1, diff-1}];
            total += cnt * (PP * (p[pro] * (cp + cm) - cm));
        }

        if (total >= db(0)) {
            mp[{deep, diff}] = 1;
        } else {
            mp[{deep, diff}] = 0;
        }

        for (auto [pro, cnt] : cntp) {
            db PP = P[pro][{deep, diff}];
            db cp = info[pro][{deep+1, diff+1}];
            db cm = info[pro][{deep+1, diff-1}];
            if (mp[{deep, diff}] == 1) {
                info[pro][{deep, diff}] = p[pro] * 2 * cp;
            } else {
                info[pro][{deep, diff}] = p[pro] * cp + (db(1)-p[pro]) * cm;
            }
        }

        

    };

    calc(calc, 0, 0, true);
    db response = 0;
    for (ll i = 0; i < n; ++i) {
        db cur = db(1000) * info[ptmp[i]][{0, 0}];
        // cout << setprecision(5) << fixed;
        // cout << "cur: " << i << " " << cur << endl;
        response += cur;
    }
    response /= db(n);
    response -= db(1000);

    cout << setprecision(16) << fixed;
    cout << response << "\n";
}