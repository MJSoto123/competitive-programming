#include<bits/stdc++.h>
using namespace std;

const int N = 10000000 + 5;
vector<int> primes;
bitset<N> composite;

void init(int n){
    for(int i = 2; i <= n; i++){
		if(not composite[i]) primes.emplace_back(i);
		for(int p : primes){
			if(i * p > n) break;
			composite[i * p] = true;
			if(i % p == 0) break;
		}
	}
}

void solve(){
    int n; cin >> n;
    long long ans = 0;
    for(auto x : primes){
        if(x > n) break;
        ans += n / x;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init(10000000);
    int tt; cin >> tt;
    while(tt--) solve();
}