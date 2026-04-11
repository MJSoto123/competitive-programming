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
    vi a(2 * n);   
    a[0] = n; a[n] = n;
    int curr = n - 1;
    rep(i, 1, n){
        a[i] = curr;
        a[2 * n - i] = curr;
        curr--;
    }

    rep(i, 0, 2 * n) cout << a[i] << " \n"[i == 2 * n - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}