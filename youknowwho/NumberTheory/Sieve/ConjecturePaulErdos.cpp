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

const int N = 1e7 + 10;
bitset<N> composite;
int dp[N];
void init(){
    for(ll i = 3; i < N; i += 2){
        if(composite[i]) continue;
        for(ll j = i * i; j < N; j += i) composite[j] = 1;
    }

    dp[2] = 1;
    for(ll i = 0; i < 10000; i++){
        for(ll j = 0; j < 100; j++){
            ll x = i * i + j * j * j * j;
            if(x % 2 && x < N && !composite[x]) dp[x] = 1;
        }
    }

    for(int i = 2; i < N; i++) dp[i] += dp[i - 1];
}

void solve(){
    int n; cin >> n;
    cout << dp[n] - 1 << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();

    int tt; cin >> tt;
    while(tt--) solve();
}