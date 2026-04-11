#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int mult(long long a, long long b){
    return (a * b) % MOD;
}

int add(long long a, long long b){
    return (a + b) % MOD;
}

int main(){
    int n; cin >> n;
    vector<long long> a(n);
    vector<long long> cnt(11);
    vector<long long> sm(11);

    for(int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    for(int i = n - 1; i >= 0; i--){
        int sz = to_string(a[i]).size();
        long long des = 10;

        for(int j = 1; j < 11; j++){
            ans = add(ans, mult(mult(a[i],  des), cnt[j]));
            ans = add(ans, sm[j]);
            des *= 10;
            cout << "j " << j << " ans " << ans << "\n";
        }
        cnt[sz]++;
        sm[sz] += a[i];
        cout << "\n";
    }

    cout << ans % MOD << "\n";
}