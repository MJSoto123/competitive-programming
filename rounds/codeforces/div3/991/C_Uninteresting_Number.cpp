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
    ll sm = accumulate(a.begin(), a.end(), 0LL);

    if(sm % 9 == 0) {cout << "YES\n"; return;}
    int two = count(a.begin(), a.end(), 2);
    int three = count(a.begin(), a.end(), 3);

    two = min(two, 8);
    three = min(three, 8);

    for(int i = 0; i <= two; i++){
        for(int j = 0; j <= three; j++){
            if((sm + 2 * i + 6 * j) % 9 == 0) {cout << "YES\n"; return;}
        }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}