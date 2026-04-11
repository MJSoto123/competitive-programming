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
    vl b(n);
    rep(i, 0, n) cin >> b[i];
    
    vl a(n);
    int id = 1;
    a[0] = id++;
    rep(i, 1, n){
        ll add = b[i] - b[i - 1];
        if(add > i) a[i] = id++;
        else a[i] = a[i - add];
    }

    rep(i, 0, n) cout << a[i] << " \n"[i == n - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}