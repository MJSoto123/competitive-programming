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

const int N = 4e6 + 10;
vector<int> fact(N, 1), finv(N, 1);
int comb(long long n, long long k){
    return mul(fact[n], mul(finv[n - k], finv[k]));
}

void init(){
    for(int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
    finv[N - 1] = inverse(fact[N - 1]);
    for(int i = N - 2; i >= 2; i--) finv[i] = mul(finv[i + 1], i + 1);
}

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;

    long long ans = 0;
    // mix[apple+banana, orange] [last grape] mix[banana, grape]
    for(int i = d; i <= c + d; i++){
        int cc = i - d;
        int ac = a + c - cc;
        int now = mul(comb(ac + b, b), comb(cc + d - 1, d - 1));
        ans = add(ans, now);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    solve();
}