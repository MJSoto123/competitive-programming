#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int add(long long a, long long b){
    return (a + b) % MOD;
}

int mul(long long a, long long b){
    return (a * b) % MOD;
}

int binpow(long long a, long long exp){
    int res = 1;
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

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(k + 1);
    dp[0] = 1;
    int inv = inverse(n);

    for(int j = 0; j <= k; j++){
        if(dp[j] == 0) continue;
        for(auto w : a){
            if(j + w > k) continue;
            dp[j + w] = add(dp[j + w], mul(dp[j], inv));
        }
    }

    int ans = 0;
    for(int i = 0; i <= k; ++i){
        if(i + a[0] > k) ans = add(ans, mul(dp[i], inv));
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}