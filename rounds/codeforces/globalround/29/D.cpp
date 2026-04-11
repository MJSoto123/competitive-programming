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
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    map<int, int> mp;
    rep(i, 0, n) mp[a[i]]++;

    vii b;
    for(auto [val, cnt] : mp) b.emplace_back(cnt, val);
    sort(all(b));
    reverse(all(b));

    n = sz(b);
    ll ali = 0, bob = 0;
    int turn = 1;
    // 1 alice
    for(auto [cnt, val] : b){
        // cout << cnt << " " << val << " => ";
        if(turn){
            ali += 1LL * ((val + 1) / 2) * cnt;
            bob += 1LL * (val / 2) * cnt;
        }else{
            bob += 1LL * ((val + 1) / 2) * cnt;
            ali += 1LL * (val / 2) * cnt;
        }
        // cout << ali << " " << bob << "\n";

        if(val % 2) turn ^= 1;
    }

    cout << ali << " " << bob << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}