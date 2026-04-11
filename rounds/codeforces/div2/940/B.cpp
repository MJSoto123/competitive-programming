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
    int n, k; cin >> n >> k;
    int pot = 1;
    while((pot * 2 - 1) <= k) pot *= 2;
    if(n == 1) cout << k << "\n";
    else {
        cout << pot - 1<< " " << k + 1 - pot << " ";
        for(int i = 0; i < n - 2; i++) cout << "0 ";
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}