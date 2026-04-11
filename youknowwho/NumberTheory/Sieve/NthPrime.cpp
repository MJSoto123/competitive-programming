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

const int N = 2e7 + 100;
bitset<N> composite;
vi primes;
void init(){
    for(ll i = 2; i < N; i++){
        if(!composite[i]) primes.emplace_back(i);
        for(auto p : primes){
            if(i * p > N) break;
            composite[i * p] = 1;
            if(i % p == 0) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    int n; cin >> n;
    cerr << primes.size() << "\n";
    cout << primes[n - 1] << "\n";
}