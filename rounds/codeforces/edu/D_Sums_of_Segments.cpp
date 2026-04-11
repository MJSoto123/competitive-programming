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
#define pii pair<int, int>
#define vl vector<ll>
#define vii vector<pair<int, int>>
using namespace std;



signed main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vl pref(n + 1);
    vl group;

    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];

    ll tot = accumulate(pref.begin(), pref.end(), 0LL);
    group.emplace_back(tot);
    for(int i = 0; i < n - 1; i++) {
        tot -= a[i] * (n - i);
        group.emplace_back(tot);
    }
    // cout << "ggroup: ";
    // for(auto x : group) cout <<  x << " ";
    // cout << "\n";


    vi ranges; ll curr = 0;
    ranges.emplace_back(0);
    for(int i = n; i >= 1; i--) {
        curr += i;
        ranges.emplace_back(curr);
    }
    // for(auto x : ranges) cout << x << " ";
    // cout << "\n";


    vi pref_groups(n + 1, 0);
    for(int i = 1; i <= n; i++) pref_groups[i] = pref_groups[i - 1] + group[i - 1];
    // cout << "pref_g: ";
    // for(auto x : pref_groups) cout <<  x << " ";
    // cout << "\n";   


    auto get = [&](int x){
        int l = -1, r = n;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(ranges[mid] < x) l = mid;
            else r = mid;
        }
        return r;
    };

    vl doublepref(n + 1);
    for(int i = 1; i <= n; i++) doublepref[i] = doublepref[i - 1] + pref[i];
    // cout << "double_pref_g: ";
    // for(auto x : doublepref) cout <<  x << " ";
    // cout << "\n"; 


    auto finalget =[&](int l, int idl){
        int l2 = l - ranges[idl - 1];
        // cout << "idl: " << idl << " l2: " << l2 << "\n";
        ll subl = doublepref[n] - doublepref[l2 - 1 + idl - 1];
        int quedan = (n - idl + 1) - (l2 - 1);

        // cout << "sub: "<< subl << " queda: " << quedan << "\n";
        // cout << pref[idl - 1] << "\n";
        subl -= pref[idl - 1] * quedan;
        return subl;
    };

    int qq; cin >> qq;
    while(qq--){
        ll l, r; cin >> l >> r;
        r++;
        int idl = get(l);
        int idr = get(r);
        ll tot = pref_groups[idr] - pref_groups[idl - 1];
        ll subl = group[idl - 1] - finalget(l, idl);
        
        ll subr = finalget(r, idr);
        // cout << tot << " " << subl << " " << subr << "\n";
        tot -= subl;
        tot -= subr;
        cout << tot << "\n";
        // int l2 = l - ranges[idl - 1];
        // ll subl = doublepref[n] - doublepref[l2 - 1 + idl - 1];
        // int quedan = n - l2;
        // subl -= pref[idl - 1] * quedan;
    }    
}