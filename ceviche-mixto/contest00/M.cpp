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

const ll inf = 1LL << 62; 

void solve() { 
    string a, b; cin >> a >> b; 
    
    vl dp(2); 
    dp[1] = inf; 

    rep(i,0,sz(a)) { 
        vl ndp(2, inf); 
        rep(last,0,2) { 
            rep(x,0,2) { 
                int cost = ((a[i] - '0') ^ x) + ((b[i] - '0') ^ x ^ last); 
                int nval = (x ^ last); 
                ndp[nval] = min(ndp[nval], dp[last] + cost); 
            }
        }
        swap(ndp, dp); 
    }
    cout << min(dp[0], dp[1]) << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt; 
    while(tt--) solve(); 

}