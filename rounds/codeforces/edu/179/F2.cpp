#include <bits/stdc++.h>
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

int getmin(int a, int b){
    return (a + b - 1);
}

int getmax(int a, int b){
    return (a * b);
}

pair<int, int> NIL(-1, -1);
vector<vector<pair<int, int>>> ans(51, vector<pair<int, int>> (51, NIL));

void init(){
    for(int i = 1; i <= 200; i++){
        for(int j = 1; j <= 200; j++){
            int mn = getmin(i, j);
            int mx = getmax(i, j);
            int p = 2 * i + 2 * j;

            for(int num = 1; num <= 50; num++){
                for(int den = 1; den <= 50; den++){
                    if((p * den) % num == 0){
                        int a = (p * den) / num;
                        if(a > 50000) continue;
                        if(a >= mn && a <= mx && ans[num][den] == NIL){
                            ans[num][den] = make_pair(i, j);
                        }
                    }
                }
            }
        }
    }
}

void solve(){
    int num, den; cin >> num >> den;
    int g = gcd(num, den);
    num /= g; den /= g;

    if(ans[num][den] == NIL){ cout << "-1\n"; return; }
    auto [r, c] = ans[num][den];

    vvi a(r, vi(c));
    for(int i = 0; i < r; i++) a[i][0] = 1;
    for(int i = 0; i < c; i++) a[0][i] = 1;

    // cout << r << " " << c << " => ";
    int p = 2 * r + 2 * c;
    int need = (p * num) / den;
    need -= (r + c - 1);

    for(int i = 1; i < r; i++){
        for(int j = 1; j < c; j++){
            if(need){
                a[i][j] = 1;
                need--;
            }
        }
    }

    cout << (p * den) / num << "\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j]) cout << i << " " << j << "\n";
            // cout << a[i][j] << " ";
        }
        // cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    init();

    int tt; cin >> tt;
    while(tt--) solve();
}