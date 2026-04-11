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


int query(int u, int v){
    cout << "? " << u << " " << v << endl;
    int ans; cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;
    vi par(n);
    par[0] = -1;
    par[1] = 0;

    set<int> head;
    // primeros
    int sec = n;
    for(int i = 2; i < n; i++){
        bool ok = query(1, i);
        head.insert(i);
        if(ok) par[i] = 0;
        else{
            par[i] = 1;
            sec = i;
            break;
        }
    }

    for(int i = sec + 1; i < n; i++){
        set<int> aux = head;
        for(auto v : head){
            bool ok = query(v, i);
            aux.erase(aux.find(v));
            if(!ok) {
                par[i] = v;
                aux.insert(i);
                break;
            }
        }
        head = aux;
    }

    cout << "! ";
    for(int i = 1; i < n; i++) cout << par[i] << " ";
    cout << endl;
}

signed main() {
    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}