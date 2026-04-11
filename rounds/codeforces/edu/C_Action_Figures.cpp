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
    string s; cin >> s;
    ll sm = 1LL * n * (n + 1) / 2;
    vi ze;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') ze.emplace_back(i);
    }

    vi on;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '1') on.emplace_back(i);
    }

    vi vis(n, 0);

    for(int i = n - 1; i >= 0; i--){
        if(ze.size() && ze.back() >= i) ze.pop_back();
        if(on.size() && on.back() >= i) on.pop_back();

        if(vis[i]) continue;
        if(s[i] == '1'){
            if(ze.size()) {
                vis[ze.back()] = 1;
                ze.pop_back();
                sm -= (i + 1);
            }else if(on.size()){
                vis[on.back()] = 1;
                on.pop_back();
                sm -= (i + 1);
            }
        }
    }
    cout << sm << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}