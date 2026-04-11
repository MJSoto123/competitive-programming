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
    int k; cin >> k;
    map<int,int> mp;
    int tmp;
    for(int i = 0 ; i < k; i++) {
        cin >> tmp;
        mp[tmp]++;
    }
    k -= 2;
    for(int i = 1; i * i <= k; i++){
        if(k % i == 0){
            int j = k / i; 
            if(i != j && mp.count(i) && mp.count(j)) {
                cout << i << " " << j << "\n";
                return;
            }else if(i == j && mp.count(i) && mp[i] >= 2) {
                cout << i << " " << j << "\n";
                return;
            }
        }
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