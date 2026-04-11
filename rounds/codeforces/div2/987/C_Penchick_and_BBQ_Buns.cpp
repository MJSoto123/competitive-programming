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
    if(n % 2 == 0) {
        for(int i = 0; i < n; i++) {
            cout << (i / 2) + 1 << " ";
        }
        cout << "\n";
        return;
    }
    
    if(n < 27){ cout << "-1\n"; return;}
    vi a(n, 0);
    a[0] = 1;
    a[9] = 1;
    a[25] = 1;
    a[10] = 2;
    a[26] = 2;
    int curr = 3;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0){
            a[i] = curr;
            a[i + 1] = curr;
            i++; curr++;
        }
    }
    for(auto x : a) cout << x << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // init();
    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}