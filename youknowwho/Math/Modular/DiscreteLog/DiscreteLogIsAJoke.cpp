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

const ll mod = 1000'000'000'000'000'000 + 31;
ll mul(ll a, ll b){
    ll r = a * b - (ll)((long double) a * b / mod + .5) * mod;
    return (r < 0 ? r + mod : r);
}

ll binpow(ll a, ll exp){
    ll res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll now = 300;
    int n; cin >> n;
    for(int i = 1e6; i > n; i--){
        now = binpow(42, now);
    }
    cout << (long long)(now) << "\n";
}