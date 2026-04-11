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

int getNext(ll x, ll a, ll b, ll c){
    return (x * a + b) % c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    ll prev, x1, x2, x3; cin >> prev >> x1 >> x2 >> x3;

    vi a(n);
    a[0] = prev;
    rep(i, 1, n) a[i] = getNext(a[i - 1], x1, x2, x3);
    
    ll block = 0;
    rep(i, 0, k) block += a[i];
    
    ll ans = block;
    rep(i, k, n){
        block += (-a[i - k] + a[i]);
        ans ^= block;
    }

    cout << ans << "\n";
}