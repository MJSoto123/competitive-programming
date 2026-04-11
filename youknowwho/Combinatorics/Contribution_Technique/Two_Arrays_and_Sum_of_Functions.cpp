#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int add(long long a, long long b){
    a %= MOD; b %= MOD;
    return ((a + b) % MOD + MOD) % MOD;
}

int mul(long long a, long long b){
    a %= MOD; b %= MOD;
    return ((a * b) % MOD + MOD) % MOD;
}

int main(){
    int n; cin >> n;
    vector<long long> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<long long> factor(n);
    for(int i = 0; i < n; i++) factor[i] = 1LL * (i + 1) * (n - i);
    for(int i = 0; i < n; i++) a[i] *= factor[i];

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    long long ans = 0;
    for(int i = 0; i < n; i++) ans = add(ans, mul(a[i], b[i]));

    cout << ans << "\n";
}