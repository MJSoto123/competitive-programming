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

const int N = 1e8 + 1;
bitset<N> composite;
vi primes;
vii ans;
void init(){
    for(ll i = 3; i < N; i += 2){
        if(composite[i]) continue;
        for(ll j = i * i; j < N; j += i) composite[j] = 1;
    }
    primes.emplace_back(2);
    for(int i = 3; i < N; i += 2) if(!composite[i]) primes.emplace_back(i);

    int r = 1, c = 1;
    int l = 1;
    for(int p : primes){
        ans.emplace_back(r, c);
        c++;
        if(c > l) c = 1, r++, l++;
    }
}

void solve(){
    int n; cin >> n;
    if(n == 2) cout << "1\n";
    else if(n % 2 == 0) cout << "-1\n";
    else if(composite[n]) cout << "-1\n";
    else{
        int l = -1, r = sz(primes);
        while(r - l > 1){
            int mid = r + l >> 1;
            if(primes[mid] <= n) l = mid;
            else r = mid;
        }
        cout << ans[l].first << " " << ans[l].second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();

    int tt; cin >> tt;
    while(tt--) solve();
}