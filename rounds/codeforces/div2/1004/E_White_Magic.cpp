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


void solve(){
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int zero = count(a.begin(), a.end(), 0);
    if(zero == 0) {cout << n << "\n"; return;}

    int idx = 0;
    for(int i = n - 1; i >= 0; i--) if(a[i] == 0) idx = i;

    vi mn = a;
    for(int i = 1; i < n; i++) mn[i] = min(mn[i - 1], a[i]); 
    
    vi b(n + 2);
    int now = 0;
    vi mex(n);
    for(int i = n - 1; i >= 1; i--){
        if((a[i] != 0 || i == idx) && a[i] <= n) b[a[i]] = 1;
        while(b[now]) now++;
        mex[i - 1] = now;
    }
    
    for(int i = 0; i < n; i++) if(mn[i] < mex[i]) {cout << n - zero << "\n"; return;}
    cout << n - zero + 1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}