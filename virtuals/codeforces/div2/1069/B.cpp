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
    int n, l, r; cin >> n >> l >> r;
    vi a(n + 1);
    vi b(n + 1);
    iota(all(b), 1);
    b[r] = b[l - 1];
    
    rep(i, 1, n + 1) a[i] = b[i] ^ b[i - 1];
    rep(i, 1, n + 1) cout << a[i] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}