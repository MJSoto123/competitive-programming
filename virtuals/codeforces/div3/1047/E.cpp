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

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi cnt(n + 10);
    rep(i, 0, n) cnt[a[i]]++;
    int mex = 0;
    auto get = [&](vi arr){
        mex = 0;
        rep(i, 0, n + 10){
            if(cnt[i]) mex++;
            else break;
        }
    };
    get(a);
    
    auto go = [&](){
        
        vi ans(n);
        for(int i = 0; i < n; i++){
            if(a[i] < mex && cnt[a[i]] == 1) ans[i] = a[i];
            else ans[i] = mex;
        }
        swap(a, ans);
        cnt.assign(n + 10, 0);
        rep(i, 0, n) cnt[a[i]]++;
        get(a);
    };

    vl ans(2);
    rep(i, 0, min(100, k)){
        go();
        ans[i % 2] = accumulate(all(a), 0LL);
    }

    if(k % 2) cout << ans[0] << "\n";
    else cout << ans[1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}