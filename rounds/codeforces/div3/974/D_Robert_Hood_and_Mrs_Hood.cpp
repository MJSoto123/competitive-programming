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
    int n, d, m; cin >> n >> d >> m;
    vi l(n + 2), r(n + 2);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        l[x]++; r[y + 1]++;
    }

    for(int i = 1; i <= n; i++) {
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }
    for(auto x : l) cout << x << " ";
    cout << "\n";

    for(auto x : r) cout << x << " ";
    cout << "\n";
    

    int idx1 = 0, val1 = 0;
    int idx2 = n, val2 = n + 1;
    for(int i = 1; i <= n - d; i++){
        int cnt = l[i] - r[i + d];
        cout << cnt << " ";
        if(cnt > val1) {
            idx1 = i; val1 = cnt;
        }

        if(cnt < val2) {
            idx2 = i; val2 = cnt;
        }
    }
    cout << "\n";
    cout << idx1 << " " << val1 << "\n";
    cout << idx2 << " " << val2 << "\n";
    cout << idx1 << " " << idx2 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}