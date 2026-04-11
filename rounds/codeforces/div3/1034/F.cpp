#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }
const int N = 100000 + 100;
vector<int> primes;
bitset<N> composite;

void lineal(int n){
    for(int i = 2; i <= n; i++) {
		if(not composite[i]) primes.emplace_back(i);
		for(int p : primes) {
			if(i * p > n) break;
			composite[i * p] = true;
			if(i % p == 0) break;
		}
	}
}

void solve(){
    int n; cin >> n;
    vi a(n + 1);
    for(int i = 0; i <= n; i++) a[i] = i;

    vi vis(n + 1);
    for(int i = n; i >= 1; i--){
        if(composite[i]) continue;
        vi b;
        for(int j = i; j <= n; j += i){
            if(!vis[j]){
                b.emplace_back(j);
                vis[j] = 1;
            }
        }
        vi rot = b;
        rotate(rot.begin(), rot.begin() + 1, rot.end());
        for(int j = 0; j < b.size(); j++) a[b[j]] = rot[j];
    }
    
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    lineal(1e5 + 10);

    int tt; cin >> tt;
    while(tt--) solve();
}