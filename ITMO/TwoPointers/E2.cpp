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
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int cnt = 0;
    int l = 0;
    map<int, int> mp;
    ll ans = 0;
    rep(r, 0, n){
        mp[a[r]]++;
        while(sz(mp) > k){
            mp[a[l]]--;
            if(mp[a[l]] == 0) mp.erase(mp.find(a[l]));
            l++;
        }
        ans += (r - l + 1);
    }

    cout << ans << "\n";
}