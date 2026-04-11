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

inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q; cin >> n >> q;
    vi nest(n + 1), id(n + 1), to(n + 1);
    iota(nest.begin(), nest.end(), 0);
    iota(id.begin(), id.end(), 0);
    iota(to.begin(), to.end(), 0);

    for(int i = 0; i < q; i++){
        int op; cin >> op;
        if(op == 1){
            int a, b; cin >> a >> b;
            int realnest = id[b];
            to[a] = realnest;
        }
        else if(op == 2){
            int a, b; cin >> a >> b;
            int ra = id[a];
            int rb = id[b];
            swap(nest[id[a]], nest[id[b]]);
            id[a] = rb;
            id[b] = ra;
        }else{
            int a; cin >> a;
            cout << nest[to[a]] << "\n";
        }

        for(int i = 0; i < n; i++){
            
        }
    }
}