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

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ans; cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vi pos(n + 1);
    for(int i = 0; i < n; i++) pos[a[i]] = i + 1;

    int u = -1;
    for(int i = 1; i <= n; i++) if(pos[i] == 0) u = i;

    if(u == -1){
        int d1 = query(pos[1], pos[n]); 
        int d2 = query(pos[n], pos[1]);
        if(d1 == d2 && d1 >= n - 1) cout << "! B" << endl;
        else cout << "! A" << endl;
    }else{        
        int d1 = query(u, a[0]); 
        if(d1 == 0) cout << "! A" << endl;
        else cout << "! B" << endl;
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}