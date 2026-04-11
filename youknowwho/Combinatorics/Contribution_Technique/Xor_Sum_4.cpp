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
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    for(int bit = 0; bit < 63; bit++){
        int ones = 0, zeros = 0;
        for(int i = 0; i < n; i++){
            if(a[i] & (1LL << bit)) ones++;
            else zeros++;
        }
        ans = add(ans, mul(1LL << bit, mul(zeros, ones)));
    }

    cout << ans << "\n";
}