#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <bitset>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <climits>
#include <numeric>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <unordered_map>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }


void print(vi a, string name){
    cout << name << ": ";
    for(auto x : a) cout << x << " ";
    cout << "\n";
}

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll mult(ll a, ll b){
    return (a * b) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vi ones(n);
    for(int i = 0; i < n; i++){
        if(a[i] == 1) ones[i]++;
        if(i > 0) ones[i] += ones[i - 1];
    }

    vi twos(n, 0);
    for(int i = 0; i < n; i++){
        if(i > 0) twos[i] = twos[i - 1];
        if(a[i] == 2 && i > 0) twos[i] += twos[i - 1] + ones[i];
        twos[i] %= MOD;
    }

    ll sm = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 3) sm += twos[i];
        sm %= MOD;
    }
    cout << sm << "\n";
}