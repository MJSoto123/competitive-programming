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

vector<vector<pair<int, int>>> g;
void read(int n, int parent) {
    for (int i = 0; i < n; i++) {
        int w, cnt; cin >> w >> cnt;
        int u = g.size();
        g.emplace_back();
        g[parent].emplace_back(u, w);
        read(cnt, u);   
    }
}

int power;
ll cuts = 0;
int solve(int u){
    vi sobra;
    for(auto [v, w] : g[u]){
        int ansv = solve(v) + w;
        cuts += ansv / power;
        ansv %= power;
        if(ansv) sobra.emplace_back(ansv);
    }

    sort(sobra.rbegin(), sobra.rend());
    ll sm = accumulate(sobra.begin(), sobra.end(), 0LL);
    for(auto wi : sobra){
        if(sm < power) break;
        cuts++;
        sm -= wi;
    }

    return (int)sm;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> power;
    g.emplace_back();
    read(1, 0);

    int sobra = solve(0);
    cout << cuts + (sobra + power - 1) / power << "\n";

}