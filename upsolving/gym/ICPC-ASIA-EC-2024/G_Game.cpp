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

inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }


const int MOD = 998244353; 
int add(int a, int b) { return (a + b) >= MOD ? a + b - MOD : a + b; }
int sub(int a, int b) { return a < b ? a - b + MOD : a - b; }
int mul(ll a, ll b) { return (a * b) % MOD; }
int binpow(int a, int exp) { 
    int ans = 1; 
    while(exp > 0) {
        if(exp & 1) ans = mul(ans, a);
        a = mul(a, a);
        exp >>= 1;
    }
    return ans; 
}
int invmod(int a) { return binpow(a, MOD - 2); }

void solve(){
    int a, b; cin >> a >> b;
    int pa, pb; cin >> pa >> pb;

    int ans = 0;
    int p = 1;
    int pt = invmod(add(pa, pb));
    pa = mul(pa, pt);
    pb = mul(pb, pt);
    int ab = mul(pa, pb);
    int invab = invmod(add(ab, -1));
    cout << pa << " " << pb << " " << pt << "\n";
    while(true){
        cerr << a << " " << b << "\n";
        if(a == b){
            cerr << p << "\n";
            p = mul(p, pa);
            cerr << p << "\n";
            ans = add(ans, p);
            break;
        }
        else if(a > b){
            int t = (a - 1)/ b;
            a = a - b * t;
            int pab = mul(p, ab);
            cerr << "t: " << t << "\n";
            int sm = mul(binpow(ab, t - 1) - 1, invab);
            ans = add(ans, mul(pab, sm));

            p = mul(p, binpow(b, t));
        }
        else if(a < b){
            int t = (b  - 1)/ a;
            cerr << "t: " << t << "\n";
            b = b - a * t;
            p = mul(p, binpow(pb, t - 1));
            if(a != b) ans = add(ans, mul(p, pa));
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}