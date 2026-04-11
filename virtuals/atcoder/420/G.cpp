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

vl ans;
void solve(ll a, ll b){
    if((a + b) % 4) return;
    ll aux = (a - b) / 2;
    ll n = (aux - 1) / 2;
    ans.emplace_back(n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k; cin >> k;
    ll x = 4 * k - 1;
    for(ll i = 1; i * i <= abs(x); i++){
        if(x % i == 0){
            solve(i, x / i);
            if(x / i != i) solve(x / i, i);
        }
    }

    sort(all(ans));
    cout << sz(ans) << "\n";
    for(auto x : ans) cout << x << " "; cout << "\n";
}