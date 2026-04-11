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

ll divide(int l, int r){
    if(r - l <= 3){
        ll ret = (1LL << 60);
        rep(i, l, r){
            rep(j, l, r){
                if(i == j) continue;
                ret = min(ret, f(p[i], p[j]));
            }
        }
        sort(p + l, p + r, [&](pii i, pii j){
            return i.second < j.second;
        });
        return ret;
    }
    int mid = l + r >> 1;
    int xmid = p[mid].first;
    ll ret = min(divide(l, mid), divide(mid, r));
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

    vii closest;
    rep(i, l, r){
        int d = p[i].first - xmid;
        if(1LL * d * d < ret) closest.emplace_back(p[i]);
    }

    rep(i, 0, sz(closest)){
        rep(j, i + 1, sz(closest)){
            ll d = f(closest[i], closest[j]);
            if(d > ret) break;
            ret = min(ret, d);
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi sm = a;
    rep(i, 1, n) sm[i] = sm[i - 1] + a[i];

    rep(i, 0, n) p[i] = {i + 1, sm[i]};
    sort(p, p + n);

    cout << divide(0, n) << "\n";
}