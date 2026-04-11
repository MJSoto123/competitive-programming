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
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = n - 1;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        vi b = a;
        for(int j = i - 1; j >= 0; j--){
            if(b[j + 1] >= b[j]) continue;
            else{
                cnt++;
                b[j] = b[j + 1];
            } 
        }

        for(int j = i; j <  n - 1; j++){
            if(b[j + 1] >= b[j]) continue;
            else{
                cnt++;
                b[j + 1] = b[j];
            } 
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}