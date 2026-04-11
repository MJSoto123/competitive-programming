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
    ll n; cin >> n;
    ll m = n;
    vi a(32);
    for(int i = 0; i < 32; i++){
        a[i] = m % 2;
        m /= 2;
    }
    
    for(int i = 0; i < 32; i++){
        if(a[i] == 1 && i + 2 < 32 && a[i + 1] == 0 && a[i + 2] == 0){
            a[i] = -1;
            a[i + 1] = 1;
        }
    }

    ll x = 0;
    for(int i = 31; i >= 0; i--){
        x *= 2; 
        x += a[i];
    }  
    for(int i = 1; i < 32; i++){
        if(a[i] == 0 && a[i] == a[i - 1]){cout << "NO\n"; return;}
    }

    if(x == n) {
        cout << "YES\n";
        for(int j = 0; j < 4; j++){
            for(int i = 0; i < 8; i++) cout << a[j * 8 + i] << " ";
            cout << "\n";
        }
        cout << "\n";    
    }else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}