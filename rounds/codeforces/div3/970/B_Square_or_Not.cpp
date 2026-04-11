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
    int sq = sqrt(n);
    if(sq * sq != n) { cout << "No\n"; return; }
    n = sq;
    for(int i = 0; i < n; i++){
        if(i == 0 || i == n - 1){
            for(int j = 0; j < n; j++){
                if(s[i * n + j] != '1'){ cout << "No\n"; return;}
            }
        } else{
            for(int j = 0; j < n; j++){
                if(j == 0 || j == n - 1){
                    if(s[i * n + j] != '1'){ cout << "No\n"; return;}    
                }else{
                    if(s[i * n + j] != '0'){ cout << "No\n"; return;}
                }
            }
        }
    }
    cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}