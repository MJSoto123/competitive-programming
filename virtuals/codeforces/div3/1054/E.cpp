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
    int n, k, l, r; cin >> n >> k >> l >> r;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = 0;
    
    int low = 0, high1 = 0, high2 = 0;
    map<int, int> mp;
    mp[a[0]]++;
    

    while(low < n && high1 < n){
        while(sz(mp) < k && high1 + 1 < n){
            high1++;
            mp[a[high1]]++;
        }

        int liml = -1, limr = -1;
        if(sz(mp) != k) break;
        if(sz(mp) == k) liml = high1;
        while(high2 + 1 < n){
            if(mp.count(a[high2 + 1])) high2++;
            else break;
        }
        limr = high2;
        int d1 = liml - low + 1, d2 = limr - low + 1;
        int in1 = max(d1, l), in2 = min(d2, r);
        if(in1 <= in2){
            ans += (in2 - in1 + 1);
        }

        mp[a[low]]--;
        if(mp[a[low]] == 0) mp.erase(a[low]);
        low++;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}