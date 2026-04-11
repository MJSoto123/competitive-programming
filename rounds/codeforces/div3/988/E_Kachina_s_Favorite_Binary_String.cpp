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


void solve(){
    int n; cin >> n;
    string s(n, '0');
    ll cnt;
    int zeros = 0;
    for(int i = n - 1; i >= 1; i--){
        cout << "? " << i << " " << i + 1 << endl;
        cin >> cnt;
        if(cnt == 1){
            s[i - 1] = '0';
            s[i] = '1';
            zeros++;
            ll ans = 1;
            for(int j = i - 1; j >= 1; j--){
                cout << "? " << j << " " << i + 1 << endl;
                cin >> cnt;
                if(cnt == ans) s[j - 1] = '1';
                else {
                    s[j - 1] = '0';
                    zeros++;
                    ans = cnt;
                }
            }
            cout << "? " << 1 << " " << n << endl;
            cin >> cnt;
            for(int ones = 0; ones <= n; ones++){
                if(ans + 1LL * ones * zeros == cnt){
                    for(int idx = 0; idx < ones; idx++) s[i + 1 + idx] = '1';
                    break;
                }
            }
            cout << "! " << s << endl;
            return;
        }
    }
    cout << "! IMPOSSIBLE" << endl;
}

signed main() {

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}