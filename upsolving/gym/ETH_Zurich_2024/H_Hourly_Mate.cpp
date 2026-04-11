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

int solve(){
    int n, m; cin >> n >> m;
    vii a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first;
    for(int i = 0; i < n; i++) cin >> a[i].second;
    if(n < m) { cout << "0\n"; return; }
    
    vvi aa(m + 1);
    for(int i = 0; i < n; i++) aa[a[i].first].emplace_back(a[i].second);    
    for(int i = 1; i <= m; i++) sort(aa[i].rbegin(), aa[i].rend());

    int k = 0;
    while(true){
        vi add;
        for(int i = 1; i <= m; i++) {
            if(aa[i].empty()) return k;
            add.emplace_back(aa[i].back());
            aa[i].pop_back();
        }
        sort(add.begin(), add.end());
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) cout << solve() << "\n";
    return 0;
}