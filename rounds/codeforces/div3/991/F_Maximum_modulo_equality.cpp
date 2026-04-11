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


struct SegmentTree {
    vi tree; 
    int n;

    SegmentTree(int n) : n(n), tree(2 * n + 5, 0) {}

    void upd(int p, int v) {
        p += n; 
        for (tree[p] = v; p > 1; p >>= 1) 
            tree[p >> 1] = gcd(tree[p], tree[p ^ 1]);
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = gcd(res, tree[l++]);
            if (r & 1) res = gcd(res, tree[--r]);
        }
        return res;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vi a(n);
    for(int  i = 0; i < n; i++) cin >> a[i];

    vi dif;
    for(int i = 1; i < n; i++) dif.emplace_back(abs(a[i] - a[i - 1]));

    SegmentTree seg(dif.size());
    for (int i = 0; i < dif.size(); i++) seg.upd(i, dif[i]);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        if(l == r) cout << "0 ";
        else cout << seg.query(l - 1, r - 1) << " ";   
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}