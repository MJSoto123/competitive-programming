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
const int BASE = 31;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

vi p;
void init(int n){
    p.assign(n + 10, 1);
    for(int i = 1; i < n + 10; i++) p[i] = (1LL * p[i - 1] * BASE) % MOD;
}

int add(long long a, long long b) {
    return ((a + b) % MOD + MOD) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k; cin >> n >> m >> k;
    k = m - k;
    init(n);

    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    
    vector<vector<int>> h(m, vector<int> (4, 0));
    for (int j = 0; j < m; j++) {
        for (int c = 0; c < 4; c++) {
            for (int i = 0; i < n; i++) {
                if (s[i][j] - 'A' == c) {
                    h[j][c] = add(h[j][c], p[i + 1]);
                }
            }
        }
    }

    int target = 0;
    for(int i = 0; i < n; i++) target = add(target, 1LL * k * p[i + 1]) % MOD;

    for (int i = 0; i < n; i++) {
        int now = 0;
        for (int j = 0; j < m; j++) {
            for (int c = 0; c < 4; c++) {
                if (s[i][j] - 'A' == c) {
                    now = add(now, h[j][c]);
                }
            }
        }

        now = add(add(now, -1LL * m * p[i + 1]), 1LL * k * p[i + 1]);
        if (now == target) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
}