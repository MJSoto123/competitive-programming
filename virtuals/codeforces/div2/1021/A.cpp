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
    string s; cin >> s;
    vi dig(10);
    rep(i, 0, 10) dig[s[i] - '0']++;

    vi ans;
    rep(i, 0, 10){
        int lim = 10 - 1 - i;
        rep(d, lim, 10){
            if(dig[d]){ 
                ans.emplace_back(d);
                dig[d]--;
                break;
            }
        }
    }

    for(auto x : ans) cout << x;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve();   
}