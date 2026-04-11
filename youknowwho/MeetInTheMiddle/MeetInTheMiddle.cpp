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

    int n, x; cin >> n >> x;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int n1 = n / 2;
    vi sm1;
    for(int mask = 0; mask < (1 << n1); mask++){
        ll now = 0;
        for(int i = 0; i < n1; i++){
            if(mask & (1 << i)) now += a[i];
        }
        if(now <= x) sm1.emplace_back(now);
    }

    int n2 = n - n1;
    vi sm2;
    for(int mask = 0; mask < (1 << n2); mask++){
        ll now = 0;
        for(int i = 0; i < n2; i++){
            if(mask & (1 << i)) now += a[n1 + i];
        }
        if(now <= x) sm2.emplace_back(now);
    }

    vi d = sm2;
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    for(int i = 0; i < sz(sm2); i++){
        sm2[i] = lower_bound(all(d), sm2[i]) - d.begin();
    }

    vi cnt(sz(d));
    for(int i = 0; i < sz(sm2); i++) cnt[sm2[i]]++;

    ll ans = 0;
    for(auto val : sm1){
        int need = x - val;
        int l = -1, r = sz(d);
        while(r - l > 1){
            int mid = l + r >> 1;
            if(d[mid] <= need) l = mid;
            else r = mid;
        }
        if(l == -1 || d[l] != need) continue;
        ans += cnt[l];
    }

    cout << ans << "\n";
}