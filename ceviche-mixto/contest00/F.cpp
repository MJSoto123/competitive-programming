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

void solve() {
    ll n;
    cin >> n;

    vl a(n);
    for (auto& e : a) cin >> e;

    ll cnt = 0;
    for (auto e : a) {
        if (e == 1) ++cnt;
    }

    ll r = n - cnt;

    bool aliceTurn = true;

    if (cnt&1) {
        aliceTurn = false;
    } 

    if (aliceTurn) {
        if (r == 0) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    } else {
        if (r == 0) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }
}