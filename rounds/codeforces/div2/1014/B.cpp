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
    string a, b; cin >> a >> b;

    vi up(2, 0);
    vi down(2, 0);
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) {
            up[a[i] - '0']++;
            down[b[i] - '0']++;
        }else{
            down[a[i] - '0']++;
            up[b[i] - '0']++;
        }
    }
    if(up[0] + down[0] >= n && up[1] <= n / 2) cout << "YES\n";
    else  cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}