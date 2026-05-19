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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    ll m = n * (n + 1) / 2;
    cout << n << endl;
    rep(i, 1, n + 1) cout << i << " " << i << "\n";
    cout << endl;

    ll sm; cin >> sm;
    cout << "! " << sm - m * 500 << endl;
}