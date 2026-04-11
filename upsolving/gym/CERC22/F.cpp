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

vi p;
int base = 31;
void init(int n){
    p.assign(n + 10, 1);
    for(int i = 1; i < n + 10; i++) p[i] = (1LL * p[i - 1] * base) % MOD;
}

int add(long long a, long long b) {
    return (a + b) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k; cin >> n >> m >> k;
    k = n - k;
    init(n);

    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    
    vvi col(m, vector<int> (4, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) {
            int c = a[j][i] - 'A';
            col[i][c] = add(col[i][c], p[j + 1]);
        }
    }

    int target = 0;
    for(int i = 0; i < n; i++) target = add(target, 1LL * k * p[i + 1]);

    for(int i = 0; i < n; i++){
        int now = 0;
        for(int j = 0; j < m; j++) {
            int c = a[i][j] - 'A';
            now = add(now, col[j][c]);
        }
        now = add(add(now, -1LL * m * p[i + 1] + 1LL * k * p[i + 1]), MOD);
        if(now == target){ cout << i + 1 << "\n"; return 0; }
    }
}