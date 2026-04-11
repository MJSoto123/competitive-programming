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

// para verificar si un substring es palindromo
// return pal[l + r] >= (r - l + 1) + 1; indexando en 0

vi manacher_odd(const vi &a) {
    int n = a.size();
    vi b(1, -1);
    rep(i, 0, n) b.emplace_back(a[i]);
    b.emplace_back(-2);

    vi len(n + 1);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        len[i] = min(r - i, len[l + (r - i)]);
        while(b[i - len[i]] == b[i + len[i]]) len[i]++;
        if(i + len[i] > r) {
            l = i - len[i];
            r = i + len[i];
        }
    }
    len.erase(begin(len));
    return len;
}

vi manacher(const vi &a) {
    vi b(1, -3);
    for(auto c : a) {
        b.emplace_back(c);
        b.emplace_back(-3);
    }
    auto res = manacher_odd(b);
    return vi(res.begin() + 1, res.end() - 1);
}

void solve(){
    int n, k; cin >> n >> k;
    vi a(n + k);
    rep(i, 0, n) cin >> a[i];

    vi cnt(n + 1);
    rep(i, 0, n) cnt[a[i]]++;

    vi p;
    rep(i, 1, n + 1) if(cnt[i] == 0) p.emplace_back(i);

    rep(i, 1, n + 1){
        if(sz(p) >= 4) break;
        if(cnt[i]) p.emplace_back(i);
    }
    while(sz(p) > 4) p.pop_back();
    int m = sz(p);
    sort(all(p));

    vi ans;
    ll best = 1e18;
    rep(mask, 0, 1 << m){
        int bits = 0;
        rep(i, 0, m) if(mask & (1 << i)) bits++;
        if(bits < 3) continue;

        vi here;
        rep(i, 0, m) if(mask & (1 << i)) here.emplace_back(p[i]);

        do{
            for(int i = n; i < n + k; i += sz(here)){
                for(int j = 0; j < sz(here); j++){
                    if(i + j >= n + k) break;
                    a[i + j] = here[j];
                }
            }
            vi d1 = manacher_odd(a);
            vi d2 = manacher(a);

            ll anshere = accumulate(all(d1), 0LL) + accumulate(all(d2), 0LL);
            if(anshere < best){
                best = anshere;
                ans = here;
            }
        }while(next_permutation(all(here)));
    }

    for(int i = n; i < n + k; i += sz(ans)){
        for(int j = 0; j < sz(ans); j++){
            if(i + j >= n + k) break;
            cout << ans[j] << " "; 
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}