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

const int N = 1e5 + 10;
bitset<N> composite;
vi primes;
vi dv(N);

void init(){
    for(ll i = 2; i < N; i++){
        if(!composite[i]) primes.emplace_back(i), dv[i] = i;
        for(auto p : primes){
            if(i * p >= N) break;
            composite[i * p] = 1;
            dv[i * p] = p; 
            if(i % p == 0) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();

    int n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<vii, int> mp;
    for(auto x : a){
        map<int, int> dvs;
        while(x != 1){
            dvs[dv[x]]++;
            x /= dv[x];
        }
        vii ret;
        for(auto [d, cnt] : dvs) if(cnt % k) ret.emplace_back(d, cnt % k);
        mp[ret]++;
    }

    ll ans = 0;
    for(auto [arr, cnt] : mp){
        vii comp;
        for(auto [d, c] : arr) comp.emplace_back(d, k - c);
        if(arr == comp) ans += 1LL * cnt * (cnt - 1);
        else ans += 1LL * cnt * mp[comp];
    }

    cout << ans / 2 << "\n";
}