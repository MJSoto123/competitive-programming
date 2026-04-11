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


int lso(int n) {return (n & (-n));}

struct FenwickTree{
    vector<int> ft; 
    FenwickTree(int m) {ft.assign(m + 1, 0);};
    int rsq(int j) {
        int sum = 0;
        for(; j; j -= lso(j)) sum += ft[j];
        return sum;
    }
    void upd(int i, int v) {
        for(; i < ft.size(); i += lso(i)) ft[i] += v;
    }
};

void solve(){
    int n, m; cin >> n >> m; 
    vector<int> a(n);   
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> b(m);
    for(int i = 0; i < n; i++) cin >> b[i].first >> b[i].second;

    vector<int> order
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    solve();
}