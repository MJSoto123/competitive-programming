#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

const int N = 1e5 + 10;
pii p[N];

ll f(pii i,pii j){
    auto [xi, yi] = i;
    auto [xj, yj] = j;
    return 1LL * (xi - xj) * (xi - xj) + 1LL * (yi - yj) * (yi - yj);
}

vii divide(int l, int r){
    if(r - l <= 3){
        vii ans(2);
        ll ret = (1LL << 60);
        rep(i, l, r){
            rep(j, l, r){
                if(i == j) continue;
                ll d = f(p[i], p[j]);
                if(d < ret){
                    ret = d;
                    ans[0] = p[i];
                    ans[1] = p[j];
                }
            }
        }
        sort(p + l, p + r, [&](pii i, pii j){
            return i.second < j.second;
        });
        return ans;
    }
    int mid = l + r >> 1;
    int xmid = p[mid].first;
    auto v1 = divide(l, mid);
    auto v2 = divide(mid, r);
    vii ans(2);
    ll ret = (1LL << 60);
    ll f1 = f(v1[0], v1[1]);
    ll f2 = f(v2[0], v2[1]);
    if(f1 < ret) ret = f1, ans = v1;
    if(f2 < ret) ret = f2, ans = v2;

    {
        vii tmp;
        int i = l, j = mid;
        while(i < mid && j < r){
            if(p[i].second < p[j].second) tmp.emplace_back(p[i++]);
            else tmp.emplace_back(p[j++]);
        }

        while(i < mid) tmp.emplace_back(p[i++]);
        while(j < r) tmp.emplace_back(p[j++]);
        rep(i, 0, sz(tmp)) p[l + i] = tmp[i];
    }

    vii b;
    rep(i, l, r){
        int d = p[i].first - xmid;
        if(1LL * d * d < ret) b.emplace_back(p[i]);
    }

    rep(i, 0, sz(b)){
        rep(j, i + 1, sz(b)){
            ll vert = b[i].second - b[j].second;
            if(vert * vert >= ret) break;
            ll d = f(b[i], b[j]);
            if(d < ret){
                ret = d;
                ans[0] = b[i];
                ans[1] = b[j];
            }
        }
    }

    return ans;
}

void solve(int n){
    rep(i, 0, n){
        double x, y; cin >> x >> y;
        p[i] = { (int)llround(x * 100), (int)llround(y * 100) };
    }
    sort(p, p + n);
    auto v = divide(0, n);
    cout << 1.0 * v[0].first / 100.0 << " " << 1.0 * v[0].second / 100.0 << " " << 1.0 * v[1].first / 100.0 << " " << 1.0 * v[1].second / 100.0 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(2);
    int n;
    while(cin >> n){
        if(n == 0) break;
        solve(n);
    }
}