#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
using ld = long double;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void solve(){
    ll n, k, pos; cin >> n >> k >> pos;
    priority_queue<ld> q;
    map<ld, ll> mp;
    rep(i, 0, n){
        int x; cin >> x;
        mp[x]++;
    }

    for(auto [val, cnt] : mp) q.emplace(val);
    while(k > 0){
        ld val = q.top(); q.pop();
        ll cnt = mp[val];
        mp.erase(val);
        if(cnt >= k){
            mp[val * 0.5] += k * 2;
            mp[val] += (cnt - k);
            k = 0;
            break;
        }else{
            mp[val * 0.5] += (cnt * 2);
            q.emplace(val * 0.5);
            k -= cnt;
        }
    }

    vector<pair<ld, ll>> fin;
    for(auto [val, cnt] : mp) fin.emplace_back(val, cnt);
    reverse(all(fin));

    for(auto [val, cnt] : fin){
        pos -= cnt;
        if(pos <= 0){ cout << val << "\n"; break; }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cout << fixed << setprecision(9);
    int tt; cin >> tt;
    while(tt--) solve();
}