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
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int x = 0, y = 0;
    set<pii> end;
    end.insert({x, y});
    while(true){
        if(abs(x- a) > 10 || abs(y - b) > 10) return false;
        for(int i  = 0; i < n; i++){
            // cout << x << " " << y << "\n";
            if(s[i] == 'N') y++;
            if(s[i] == 'S') y--;
            if(s[i] == 'E') x++;
            if(s[i] == 'W') x--;
            if(x == a && y == b) return true;
        }
        if(end.find({x, y}) != end.end())  return false;
        else end.insert({x, y});
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--){
        cout << (solve() ? "YES" : "NO");
        cout << "\n"; 
    }
    return 0;
}