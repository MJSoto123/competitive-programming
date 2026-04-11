#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(long long a, long long b){
    a %= MOD; b %= MOD;
    return ((a + b) % MOD + MOD) % MOD;
}

int mul(long long a, long long b){
    a %= MOD; b %= MOD;
    return ((a * b) % MOD + MOD) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int p = 1;
    for(int i = 2; i <= n - 1; i++) p = mul(p, i);
    
    vector<int> ones(32, 0);
    for(int bit = 0; bit < 32; bit++){
        for(int i = 0; i < n; i++) {
            if(a[i] & (1 << bit)) ones[bit]++;
        }
    }
    
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int bit = 0; bit < 32; bit++){
            int now = ones[bit];
            if(b[i] & (1 << bit)) now = n - ones[bit];
            
            ans = add(ans, mul(now, (1 << bit)));
        }
    }

    ans = mul(ans, p);
    cout << ans << "\n";
}