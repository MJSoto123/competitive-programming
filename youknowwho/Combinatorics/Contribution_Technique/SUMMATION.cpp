#include<bits/stdc++.h>
using namespace std;

const int MOD = 100000007;

int add(long long a, long long b){
    return ((a + b) % MOD + MOD) % MOD;
}

int mul(long long a, long long b){
    return ((a * b) % MOD + MOD) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    for(int t = 1; t <= tt; t++){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        
        int pot = 1;
        for(int i = 0; i < n - 1; i++) pot = mul(pot, 2);

        long long ans = 0;
        for(int i = 0; i < n; i++) ans = add(ans, mul(a[i], pot));

        cout << "Case " << t << ": " << ans << "\n";
    }
}