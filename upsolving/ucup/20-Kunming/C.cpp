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

void go(ll n, ll k){
    if(n <= k) return n;
    ll subs = (n + k - 1) / k;
    
}

void solve(){
    ll n, k; cin >> n >> k;
    ll sq = sqrt(n) - 1;
    while((sq + 1) * (sq + 1) <= n) sq++;
    
    if(k <= sq){ cout << go(n, k) << "\n"; return; }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}