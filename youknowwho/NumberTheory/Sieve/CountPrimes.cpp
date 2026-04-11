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

const int N = 5e6 + 100;
bitset<N> composite;
vi primes;

int countPrimes(int n){
    for(int i = 2; i <= n; i++){
        if(!composite[i]) primes.emplace_back(i);
        for(int p : primes){
            if(i * p > n) break;
            composite[i * p] = true;
            if(i % p == 0) break;
        }
    }
    return primes.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cout << countPrimes(n) << "\n";
}