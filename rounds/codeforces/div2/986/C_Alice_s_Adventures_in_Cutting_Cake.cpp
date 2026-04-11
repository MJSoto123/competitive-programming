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

vi a;
int n, m, v;

ll get_ans(){
    vi pref(n + 1);
    int curr = 0;
    for(int i = 0; i < n; i++){
        curr += a[i];
        pref[i + 1] = pref[i];
        if(curr >= v) {
            pref[i + 1]++;
            curr = 0;
        }
    }

    // for(auto x : pref) cout << x << " ";
    // cout << "\n";

    auto get = [&](int val){
        int l = -1, r = n + 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(pref[mid] >= val) r = mid;
            else l = mid;
        }
        return r;
    };

    vl acum(n + 1);
    for(int i = 0; i < n; i++) acum[i + 1] = acum[i]  + a[i];

    int cnt = 0;
    curr = 0;
    ll ans = -1;
    for(int i = n; i >= 0; i--){
        // cout << "i: " << i << " => ";
        ll sm = 0;
        if(cnt == m) {
            for(int j = 0; j < i; j++) sm += a[j];
            return max(ans, sm);
        }

        if(i < n) curr += a[i];
        if(curr >= v) {
            cnt++;
            curr = 0;
        }
        int idx = get(m - cnt);

        // cout << "idx: " << idx << " ";
        if(idx <= i) {
            sm  = acum[i] - acum[idx];
            ans = max(ans, sm);
        }
        // cout << "ans: " << ans << "\n";
    }
    return ans;
}

void solve(){
    cin >> n >> m >> v;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    ll ans = get_ans();
    // cout << "fs: "<< ans << "\n";
    reverse(a.begin(), a.end());
    ans = max(ans, get_ans());

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}