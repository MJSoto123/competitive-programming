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

vl dp(3e5 + 100, 0);
void init(){
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i < 3e5 + 100; i++){
        dp[i] = dp[i - 1] + 1LL * 2 * (i - 1) * dp[i - 2];
        dp[i] %= MOD;
    }
}

void solve(){
    int n, k; cin >> n >> k;
    int rem = n;
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        rem--;
        if(a != b) rem--;
    }    
    cout << dp[rem] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    init();
    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}