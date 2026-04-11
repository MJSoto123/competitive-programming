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
inline int gcd(int a, int b) { while (b != 0) swap(b, a %= b); return a; }


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi b(n);
    for (int k = 1; k <= 10000; k++) {
        double f = (double) k / a[0];

        int g = 0;
        for (int i = 0; i < n; i++) {
            b[i] = round(a[i] * f);
            g = gcd(g, b[i]);
        }

        for (int i = 0; i < n; i++) b[i] /= g;

        double normal = 0;
        for (int i = 0; i < n; i++) normal += (double)b[i] * b[i];
        normal = sqrt(normal);

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (abs(a[i] - ((double)b[i] / normal)) >= 1e-6 || b[i] < 1 || b[i] > 10000) {
                ok = false;
                break;
            }
        }

        if (ok) {
            for (auto x : b) cout << x << "\n";
            return 0;
        }
    }
}