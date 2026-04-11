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
    string s; cin >> s;
    vi a;
    for(auto x : s) a.emplace_back(x - '0');
    int n = a.size();
    for(int i = 0; i < n; i++){
        int dig = -1;
        int pos = -1;
        for(int j = 0; j <= 9; j++){
            if(i + j >= n) continue;
            if(a[i + j] - j > dig) {
                dig = a[i + j] - j;
                pos = j;
            }
        }
        for(int j = pos; j > 0; j--) swap(a[i + j - 1], a[i + j]);
        a[i] -= pos; 
    }
    for(auto x : a) cout << x;
    cout <<"\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}