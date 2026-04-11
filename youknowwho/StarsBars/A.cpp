#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int add(long long a, long long b){
    return (a + b) % MOD;
}

int mul(long long a, long long b){
    return (a * b) % MOD;
}

int binpow(long long a, long long exp){
    long long res = 1;
    while(exp){
        if(exp & 1) res = mul(res, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return res;
}

int inverse(long long a){
    return binpow(a, MOD - 2);
}

const int N = 2e6 + 100;
vector<int> fact(N, 1), finv(N, 1);
void init(){
    for(int i = 2; i < N; i++) fact[i] = mul(fact[i - 1], i);
    finv[N - 1] = inverse(fact[N - 1]);

    for(int i = N - 2; i >= 2; i--) finv[i] = mul(finv[i + 1], i + 1);
}

int comb(long long n, long long k){
    return mul(fact[n], mul(finv[n - k], finv[k]));
}

void solve(){
    int n, k; cin >> n >> k;
    cout << comb(n + k - 1, k - 1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int tt; cin >> tt;
    for(int i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}