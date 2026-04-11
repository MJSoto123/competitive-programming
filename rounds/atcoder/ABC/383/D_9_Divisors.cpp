#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <bitset>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <climits>
#include <numeric>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <unordered_map>
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

const int N = 1000000 + 5;
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin >> n;
    vi p2, p3;
    ll ans = 0;
    lineal(N - 3);
    for(int i = 0; i < primes.size(); i++){
        ll x = primes[i];
        int l = -1, r = primes.size();
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(1LL * x * x <= n / (1LL * primes[mid] * primes[mid])) l = mid;
            else r = mid;
        }
        if(l > i) {
            // cout << x << " " << primes[l] << " " << x * x * primes[l] * primes[l] << " add: " << l - i << "\n";
            ans += (l - i);
        }
    }

    ll add = sqrt(sqrt(sqrt(n)));
    int l = -1, r = primes.size();
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(primes[mid] > add) r = mid;
        else l = mid;
    }
    if(l >= 0) ans += (l + 1);
       
    cout << ans << "\n";
}