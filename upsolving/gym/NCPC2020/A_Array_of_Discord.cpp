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
#define pll pair<ll,ll>
#define vl vector<long long>
#define vii vector<pair<int,int>>
#define int ll
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    auto get = [&](ll x){
        string xx = "";
        if(x == 0) {
            xx += '0';
            return xx;
        }
        while(x > 0){
            xx += char('0' + x % 10);
            x /= 10;
        }
        reverse(xx.begin(), xx.end());
        return xx;
    };

    auto getnum = [&](string s){
        ll x = 0;
        for(auto c : s){
            x *= 10;
            x += c - '0';
        }
        return x;
    };

    for(int i = 0; i < n; i++) {
        ll act = a[i];
        // cout << "try: " << act << " => ";
        string s = get(a[i]);
        // cout << "act: " << s << " ";
        if(s.size() == 1){
            s[0] = '0';
            a[i] = getnum(s);
            // cout << a[i] << " ";
            if(!is_sorted(a.begin(), a.end())){
                for(auto x : a) cout << x << " ";
                cout << "\n";
                return 0;
            }
        }
        s[0] = '1';
        a[i] = getnum(s);
        // cout << a[i] << " ";
        if(!is_sorted(a.begin(), a.end())){
            for(auto x : a) cout << x << " ";
            cout << "\n";
            return 0;
        }

        s[0] = '9';
        a[i] = getnum(s);
        // cout << a[i] << " ";
        if(!is_sorted(a.begin(), a.end())){
            for(auto x : a) cout << x << " ";
            cout << "\n";
            return 0;
        }
        a[i] = act;
        // cout << "\n";
    }
    cout << "impossible\n";
}