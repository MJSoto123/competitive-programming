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
vi dv(N);
vi primes;
void init(){
    for(ll i = 2; i < N; i++){
        if(!dv[i]){
            primes.emplace_back(i);
            dv[i] = i;
        }
        for(auto p : primes){
            if(i * p > N) break;
            dv[i * p] = p;
            if(i % p == 0) break;
        }
    }
}

void solve(int n){
    vi ans;
    while(n != 1){
        ans.emplace_back(dv[n]);
        n /= dv[n];
    }
    sort(ans.begin(), ans.end());

    cout << 1;
    for(auto x : ans) cout << " x " << x;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();

    int n;
    while(cin >> n) solve(n);
}