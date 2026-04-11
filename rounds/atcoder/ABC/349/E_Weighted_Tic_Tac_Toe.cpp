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
#define TAK 0
#define OKI 1
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }

vvi a(3, vi(3));
vvi state(3, vi(3, -1));

bool equal(int a, int b, int c){
    if(a == b && b == c && a != -1) return a;
    else return a ^ 1;
}

bool check(){
    for(int i = 0; i < 3; i++){
        if(equal(state[i][0], state[i][1], state[i][2])) return state[i][0];
        if(equal(state[0][i], state[1][i], state[2][i])) return state[0][i];
    }
    if(equal(state[0][0], state[1][1], state[2][2])) return state[0][0];
    if(equal(state[0][2], state[1][1], state[2][0])) return state[0][2];

    int plays = 0, sm0 = 0, sm1 = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            plays += (state[i][j] != -1);
            if(state[i][j] == 0) sm0 += a[i][j];
            if(state[i][j] == 1) sm1 += a[i][j];
        }
    }

    if(plays == 0) return sm1 > sm0;
    return -1;
}

bool game(int turn){
    int chk = check();
    if(chk != 1) return check();

    vi results(3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(state[i][j] != -1) continue;
            state[i][j] = turn;
            results[game(turn ^ 1)]++;
            state[i][j] = -1;
        }
    }

    int wins = results[turn];
    int loses = results[turn ^ 1];

    if(wins) return turn;
    else return turn ^ 1;
}

void solve(){
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> a[i][j];
    cout << (game(0) ? "Aoki" : "Takahashi");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    return 0;
}