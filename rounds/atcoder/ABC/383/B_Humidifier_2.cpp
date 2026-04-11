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


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, d; cin >> n >> m >> d;

    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 0;
    for(int r1 = 0; r1 < n; r1++){
        for(int c1 = 0; c1 < m; c1++){
            for(int r2 = 0; r2 < n; r2++){
                for(int c2 = 0; c2 < m; c2++){
                    if(a[r1][c1] == '#' || a[r2][c2] == '#') continue;
                    int curr = 0;
                    for(int i = 0; i < n; i++){
                        for(int j = 0; j < m; j++){
                            if((
                                abs(r1 - i) + abs(c1 - j) <= d 
                                || abs(r2 - i) + abs(c2 - j) <= d
                            ) && a[i][j] == '.') curr++;
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }
    }
    cout << ans << "\n";
}