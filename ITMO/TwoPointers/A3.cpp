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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, sm; cin >> n >> sm;
    vl a(n);
    rep(i, 0, n) cin >> a[i];
    ll tot = accumulate(all(a), 0LL);

    vl pre(n + 1);
    rep(i, 0, n) pre[i + 1] = pre[i] + a[i];

    vector<pair<ll, ll>> ans;
    rep(l, 0, n){
        rep(r, 0, n){
            ll cur = 0;
            ll len = 0;
            if(l <= r){ 
                cur += pre[r + 1] - pre[l];
                len += (r - l + 1);
            }else{
                cur += pre[n] - pre[l];
                cur += pre[r + 1];
                len += (n - l);
                len += (r + 1);
            }
            ll need = sm - cur;
            len += ((need + tot - 1)/ tot) * n;
            ans.emplace_back(len, l);
        }
    }

    sort(all(ans));
    cout << ans[0].second + 1 << " " << ans[0].first << "\n";
}