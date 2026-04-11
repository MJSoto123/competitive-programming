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
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int l = 0, r = 0;
    map<int, int> mp;
    int last = -1;
    while(true){
        // cout << l << " " << r << " => " ;
        // cout << a[l] << " " << a[r] << " ";
        if(r + 1 >= n) break;
        if(a[r] == a[r + 1]) {
            // cout << "cumple con: " << a[r] << " " << a[r + 1] << " "; 
            if(last == - 1) l = r;
            if(mp[a[r]] != 0) {
                // cout << "rep\n";
                while(mp[a[r]] != 0) {
                    mp[a[l]]--;
                    l++;
                }
            }
            last = a[r];
            mp[a[r]] += 2;
            r = r + 2;
            // cout << "newl: " << l << " ";
            // cout << "newr: " << r << " ";
            ans = max(ans, r - l);
            // cout << "ans:" << ans << "\n";
            continue;
        }
        mp.clear();
        if(last == a[r]) {
            l = r - 1;
            mp[a[r]] += 2;
        }
        else {
            l = r + 1;
            last = -1;
        }
        r++;
        // cout << "ans:" << ans << "\n";
    }
    cout << ans;
}