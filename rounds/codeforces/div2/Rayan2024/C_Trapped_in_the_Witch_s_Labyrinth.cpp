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

string moves = "RDLU";
vi dx = {0, 1, 0, -1};
vi dy = {1, 0, -1, 0};

int id(char c){
    for(int i = 0; i < 4; i++){
        if(moves[i] == c) return i;
    }
}

void solve(){ 
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vvi vis(n, vi(m, 0));
    vvi bads(n, vi(m, 0));
    queue<pii> bad;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // cout << "\ngo: " << a[i][j] << "\n";
            if(a[i][j] == '?') continue;
            int mv = id(a[i][j]);
            int nx = i + dx[mv];
            int ny = j + dy[mv];
            // cout << "to " << nx << " " << ny << "\n";
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                bad.emplace(i, j);
                vis[i][j] = 1;
                bads[i][j] = 1;
                // cout << "is bad!!\n";
            }
        
            while(!bad.empty()){
                int x, y; tie(x, y) = bad.front(); bad.pop();
                vis[x][y] = 1;
                // cout << "in " << x << " " << y << "\n";
                for(int ix = 0; ix < 4; ix++){
                    int x2 = x + dx[ix];
                    int y2 = y + dy[ix];
                    if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && a[x2][y2] != '?' && !vis[x2][y2]){
                        // cout << "try " << x2 << " " << y2 << "\n";
                        // cout << "from " << a[x2][y2] << " ";
                        int mv2 = id(a[x2][y2]);
                        int nx2 = x2 + dx[mv2];
                        int ny2 = y2 + dy[mv2];
                        // cout << "point to " << nx2 << " " << ny2 << "\n"; 
                        if(nx2 == x && ny2 == y) {
                            // cout << "bad\n";
                            bad.emplace(x2, y2);
                            vis[x2][y2] = 1;
                            bads[x2][y2] = 1;
                        }else {
                            // cout << "no bad\n";
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // cout << bads[i][j] << " ";
            if(bads[i][j]) continue;
            for(int ix = 0; ix < 4; ix++){
                int i2 = i + dx[ix];
                int j2 = j + dy[ix];
                if(i2 >= 0 && i2 < n && j2 >= 0 && j2 < m && bads[i2][j2] == 0) {
                    ans++;
                    break;
                }
            }
        }
        // cout << "\n";
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int tt; cin >> tt;
    while(tt--) solve();    
    return 0;
}