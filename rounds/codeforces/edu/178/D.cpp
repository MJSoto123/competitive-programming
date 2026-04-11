#include<bits/stdc++.h>
using namespace std;

const int N = 10000000 + 5;
vector<int> primes;
vector<long long> pre;
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.rbegin(), a.rend());
    long long sm = accumulate(a.begin(), a.end(), 0LL);


    for(int i = 0; i <= n; i++){
        if(sm >= pre[n - i]) {
            cout << i << "\n";
            return;
        }
        sm -= a.back();
        if(!a.empty())a.pop_back();
    }
    cout << n << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    lineal(10000000);
    long long sm = 0;
    for(int i = 0; i < primes.size(); i++){
        pre.emplace_back(sm);
        sm += primes[i];
    }

    int tt; cin >> tt;
    while(tt--) solve();
}