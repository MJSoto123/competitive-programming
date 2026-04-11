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

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    map<int, vi> mp;
    int cur = 0;
    mp[0].emplace_back(0);
    rep(i, 0, n){
        if(s[i] == 'a') cur++;
        else cur--;
        mp[cur].emplace_back(i + 1);
    }
    if(cur == 0){ cout << "0\n"; return; }
    int ans = n;
    cur = 0;
    for(int i = n - 1; i >= 0; i--){
        if(mp.count(-cur)){
            int low = -1, high = mp[-cur].size();
            while(high - low > 1){
                int mid = low + high >> 1;
                if(mp[-cur][mid] <= i + 1) low = mid;
                else high = mid;
            }
            
            if(low != -1) {
                ans = min(ans, i + 1 - mp[-cur][low]);
            }
        }
        if(s[i] == 'a') cur++;
        else cur--;
    }

    if(ans == n) ans = - 1;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}