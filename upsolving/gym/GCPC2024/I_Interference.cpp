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
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, w; cin >> n >> w;
    vi ops;
    vi ini, dis, amp;

    for(int i = 0; i < n; i++){
        char op; cin >> op;
        if(op == '!'){
            int a, b, c; cin >> a >> b >> c;
            ini.emplace_back(a); 
            dis.emplace_back(b); 
            amp.emplace_back(c); 
        }else{
            int p; cin >> p;
            int ans = 0;
            for(int j = 0; j < ini.size(); j++){
                if(p >= ini[j] && p <= ini[j] + dis[j] - 1){
                    int aux = p - ini[j];
                    if(aux % 4 == 0) ans += amp[j];
                    if(aux % 4 == 2) ans -= amp[j];
                }
            }
            cout << ans << "\n";
        }
    } 
}