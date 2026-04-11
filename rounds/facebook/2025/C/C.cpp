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

    vi b(n);
    int cur = 0;
    rep(i, 0, n){
        cur ^= a[i];
        if(cur == 0) b[i] = 1;
    }

    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    for(int i = 1; i <= tt; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}