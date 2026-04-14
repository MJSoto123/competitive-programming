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
typedef unsigned long long ull;

const int N = 1e6 + 5;
bitset<N> composite;

vi primes;
void init(){
    for(int i = 2; i < N; i++){
        if(composite[i]) continue;
        primes.emplace_back(i);
        for(auto p : primes){
            if(i * p >= N) break;
            composite[i * p] = 1;
            if(i % p == 0) break;
        }
    }
}

void solve(){
    int n; cin >> n;
    vl a(n); 
    rep(i, 0, n) cin >> a[i];

    vl fact;
    for(auto x : a){
        for(auto p : primes){
            if(p * p > x) break;
            while(x % p == 0){
                fact.emplace_back(p);
                x /= p;
            }
        }
        if(x != 1) fact.emplace_back(x);
    }

    sort(all(fact));
    fact.erase(unique(all(fact)), fact.end());

    cout << sz(fact) << "\n";
    for(auto x : fact) cout << x << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    int tt; cin >> tt;
    rep(i, 0, tt){
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}