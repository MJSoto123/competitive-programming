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
    ll k, x; cin >> k >> x;
    int mx = 0;
    for(int i = 62; i >= 0; i--){
        if(x % (1LL << i) == 0){ mx = i; break; }
    }

    cout << (k - mx) << "\n";
    ll now = x - (1LL << (k - mx));

    rep(i, 1, k - mx + 1){
        cout << now << "\n";
        if(now & (1LL << (k + 1 - i))){
            cout << "2 ";
            now -= (1LL << (k + 1 - i));
        }
        else cout << "1 ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}