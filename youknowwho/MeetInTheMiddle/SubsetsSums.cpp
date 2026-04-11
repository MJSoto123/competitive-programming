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

    int n, A, B; cin >> n >> A >> B;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int n1 = n / 2;
    vl sm1(1 << n1);
    for(int mask = 0; mask < (1 << n1); mask++){
        ll now = 0;
        for(int i = 0; i < n1; i++){
            if(mask & (1 << i)) now += a[i];
        }
        sm1[mask] = now;
    }

    int n2 = n - n1;
    vl sm2(1 << n2);
    for(int mask = 0; mask < (1 << n2); mask++){
        ll now = 0;
        for(int i = 0; i < n2; i++){
            if(mask & (1 << i)) now += a[n1 + i];
        }
        sm2[mask] = now;
    }

    vl d = sm2;
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    for(auto &x : sm2) x = lower_bound(all(d), x) - d.begin();
    vl cnt(sz(d));
    for(auto x : sm2) cnt[x]++;
    
    vl pre(sz(cnt) + 1);
    for(int i = 1; i <= sz(cnt); i++) pre[i] = pre[i - 1] + cnt[i - 1];

    ll ans = 0;
    for(auto val : sm1){
        int low = min(B - val, A - val);
        int high = max(B - val, A - val);

        int l = -1, r = sz(d);
        while(r - l > 1){
            int mid = l + r >> 1;
            if(d[mid] >= low) r = mid;
            else l = mid;
        }

        if(r == sz(d)) continue;
        ll add = -pre[r];
        l = -1, r = sz(d);
        while(r - l > 1){
            int mid = l + r >> 1;
            if(d[mid] <= high) l = mid;
            else r = mid;
        }
        add += pre[l + 1];
        ans += add;
    } 

    cout << ans << "\n";
}