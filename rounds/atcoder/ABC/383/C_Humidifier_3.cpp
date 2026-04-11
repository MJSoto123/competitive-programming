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

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, d; cin >> n >> m >> d;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vvi vis(n, vi(m));
    int ans = 0;
    priority_queue<tuple<int,int,int>> q; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'H') {
                vis[i][j] = 1;
                ans++;
                if(d > 0) q.emplace(d - 1, i, j);
            }
        }
    }

    while(!q.empty()){
        int dcurr, i, j; tie(dcurr, i, j) = q.top(); q.pop();
        for(int x = 0; x < 4; x++){
            int ni = i + dx[x];
            int nj = j + dy[x];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] == '.' && !vis[ni][nj]){
                vis[ni][nj] = 1;
                ans++;
                if(dcurr > 0) q.emplace(dcurr - 1, ni, nj);
            }
        }
    }

    // for(auto x: vis){
    //     for(auto y: x) cout << y << " ";
    //     cout << "\n";
    // }
    cout << ans << "\n";
}