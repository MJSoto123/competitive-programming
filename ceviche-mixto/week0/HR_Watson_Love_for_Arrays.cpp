#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)
#define dbg(a) cerr << (#a) << "\t"; for(auto x  : a) cerr << x << " "; cerr << "\n";

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int m; 
int mul(ll a, ll b){ return (a * b) % m; }

void solve(){
    int n, k; cin >> n >> m >> k;   
    vi a(n);
    rep(i, 0, n) cin >> a[i], a[i] %= m;

    ll ans = 0;
    if(k == 0){
        vi pos(n);
        int last = n;
        for(int i = n - 1; i >= 0; i--){
            if(a[i] == 0) last = i;
            pos[i] = last;
        }

        rep(i, 0, n) ans += (n - pos[i]);
        cout << ans << "\n";
        return;
    }

    vvi b;
    vi tmp;
    rep(i, 0, n){
        if(a[i] == 0){
            if(sz(tmp)) b.emplace_back(tmp);
            tmp.clear();
        }
        else tmp.emplace_back(a[i]);
    }

    if(sz(tmp)) b.emplace_back(tmp);
    for(auto v : b){
        int n2 = sz(v);
        vi pre(n2);
        pre[0] = v[0];
        rep(i, 1, n2) pre[i] = mul(pre[i - 1], v[i]);
        
        map<int, int> cnt;
        rep(i, 0, n2) cnt[pre[i]]++;
        
        int target = k;
        rep(i, 0, n2){
            ans += cnt[target];
            cnt[pre[i]]--;
            target = mul(k, pre[i]);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}