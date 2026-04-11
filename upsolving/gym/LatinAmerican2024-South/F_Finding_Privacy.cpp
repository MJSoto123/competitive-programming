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

int get(int l){
    if(l % 3 == 0) return l / 3;
    else return l / 3 + 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, n; cin >> k >> n;

    int mn = (n + 2) / 3;
    int mx = (n + 1) / 2;

    if(k < mn || k > mx) { cout << "*\n"; return 0;}
    for(int i = 0; i < k; i++){
        int x = i + get(n - 2 * i);
        if(x == k) {
            string ans = "";
            for(int j = 0; j < i; j++) ans += "X-";
            while(ans.size() + 3 <= n) ans += "X--";
            if(n - ans.size() == 2) ans += "X-";
            if(n - ans.size() == 1) ans += "X";
            if(ans[n - 1] == '-' && ans[n - 2] == '-'){
                ans.pop_back();
                ans = "-" + ans;
            }
            cout << ans << "\n";
            return 0;
        }
    }

}