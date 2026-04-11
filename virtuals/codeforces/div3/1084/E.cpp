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

vi primes;
map<int, int> pot;
const int N = 1e6 + 10;
bitset<N> composite;

void init(){
    for(int i = 2; i <= N; i++){
        if(!composite[i]) primes.emplace_back(i);
        for(int p : primes){
            if(i * p > N) break;
            composite[i * p] = 1;
            if(i % p == 0) break;
        }
    }

    for(auto p : primes){
        ll cur = p;
        while(cur < N){
            pot[cur] = p;
            cur *= p;
        }
    }
    pot[1] = 1;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    
    if(is_sorted(all(a))){ cout << "Bob\n"; return; }
    vi b(n);
    rep(i, 0, n){
        if(pot.count(a[i])) b[i] = pot[a[i]];
        else { cout << "Alice\n"; return; }
    }

    if(is_sorted(all(b))) cout << "Bob\n";
    else cout << "Alice\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int tt; cin >> tt;
    while(tt--) solve();
}