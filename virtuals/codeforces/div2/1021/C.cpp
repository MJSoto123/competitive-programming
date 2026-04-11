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
    map<int, int> mp;

    rep(i, 0, n){
        int x; cin >> x;
        mp[x]++;
    }

    int bit = 2;
    int nxt = -1;
    for(auto [val, cnt] : mp){
        if(val != nxt) bit = 2;
        if(bit * 2 <= cnt){ cout << "Yes\n"; return; }
        if(bit == 2){
            if(cnt == 1) bit = 2;
            if(cnt >= 2) bit = 1;
        } else{
            if(cnt == 1) bit = 1;
        }
        nxt = val + 1;
    }
    cout << "No\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}