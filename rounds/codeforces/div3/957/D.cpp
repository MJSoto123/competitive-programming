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


bool solve(){
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    s = 'L' + s + 'L';
    int pos = 0;
    while(true){
        if(pos + m >= n + 1) return 1;
        int newL = -1;
        for(int i = pos + 1; i <= pos + m; i++) {
            if(s[i] == 'L') { newL = i; break; }
        }
        if(newL != -1) {pos = newL; continue;}
        pos = pos + m;
        while(k){
            if(s[pos] == 'L') break;
            if(s[pos] == 'C') return 0;
            if(s[pos] == 'W') {pos++; k--;}
        }
        if(s[pos] != 'L') return 0;
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tt; cin >> tt;
    while(tt--) cout << (solve() ? "YES\n" : "NO\n");
    return 0;
}