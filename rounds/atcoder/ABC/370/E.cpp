#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int add(long long a, long long b){
    return (a + b + MOD) % MOD;
}   

int mul(long long a, long long b){
    return (a * b) % MOD;
}

void solve(){
    int n; cin >> n;
    long long k; cin >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<long long> pre(n + 1);
    for(int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];

    vector<int> dp(n + 1);
    dp[n] = 1;  
    long long now = dp[n]; 

    map<long long, int> mp;
    mp[pre[n]] = dp[n];
    
    for(int i = n - 1; i >= 0; i--){
        dp[i] = now;
        if(mp.count(pre[i] + k)) dp[i] = add(dp[i], -mp[pre[i] + k]);
        
        now = add(now, dp[i]);
        mp[pre[i]] = add(mp[pre[i]], dp[i]);
    }
    
    cout << dp[0] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}
