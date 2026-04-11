#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int add(long long a, long long b){
    return ((a + b) % MOD + MOD) % MOD;
}

int mul(long long a, long long b){
    return ((a * b) % MOD + MOD) % MOD;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int pot = 1;
    for(int i = 0; i < n - 2; i++) pot = mul(pot, 2);

    sort(a.begin(), a.end());
    long long ans = 0;
    
    for(int i = 1; i < n; i++){
        int factor = mul(i, n - i);
        ans = add(ans, mul(factor, a[i] - a[i - 1]));
    }

    ans = mul(ans, pot);
    cout << ans << "\n";
}