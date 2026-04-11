#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

const int N = 100;
int grid[N][N];

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int m, n; cin >> m >> n;
    n++; m++;
    int q; cin >> q;
    int id = 1;
    string s; 
    int r, c, w, h, nr, nc;

    auto print = [&](){
        rep(i, 0, n + 2){
            rep(j, 0, m + 2) cout << grid[i][j] << " "; 
            cout << endl;
        }
        cout << endl;
    };

    auto bad = [&](int i){
        // cerr << "fail on " << i << endl;
        cout << s << " " << r - 1 << " " << c - 1 << " " << w << " " << h << endl;
    };

    auto used = [&](int color){
        rep(i, r - 1, nr + 2) rep(j, c - 1, nc + 2){
            if(grid[i][j] != color && grid[i][j] != 0) return true;
        }
        return false;
    };

    auto mark = [&](int color){
        rep(i, r, nr + 1) rep(j, c, nc + 1) grid[i][j] = color;
    };

    auto get = [&](int color){
        int r1 = -1, c1 = -1, r2, c2;
        rep(i, 0, n + 2) rep(j, 0, m + 2) if(grid[i][j] == color){
            if(r1 == -1){ r1 = i; c1 = j; }
            r2 = i; c2 = j;
        }
        return make_tuple(r1, c1, r2, c2);
    };

    rep(qq, 0, q){
        // print();
        cin >> s >> r >> c >> w >> h; r++; c++;
        if(r < 1 || c < 1){ bad(-1); continue; }
        nr = r + h - 1; nc = c + w - 1;
        if(s == "draw"){
            if(r > n || c > m || nr > n || nc > m){ bad(1); continue; }
            if(used(0)){ bad(2); continue; }
            mark(id); id++;
        }
        if(s == "remove"){
            if(r > n || c > m || nr > n || nc > m){ bad(1); continue; }
            int color = grid[r][c];
            if(color == 0){ bad(2); continue; }
            auto [r1, c1, r2, c2] = get(color);
            if(r1 != r || c1 != c || r2 != nr || c2 != nc){ bad(3); continue; }
            mark(0);
        }

        if(s == "extend"){
            if(r > n || c > m || nr > n || nc > m){ bad(1); continue; }
            int color = grid[r][c];
            if(color == 0){ bad(2); continue; }
            if(used(color)){ bad(3); continue; }
            auto [r1, c1, r2, c2] = get(color);
            if(r1 != r || c1 != c){ bad(4); continue; }
            int h1 = r2 - r1 + 1, w1 = c2 - c1 + 1;
            if(h1 > h || w1 > w){ bad(5); continue; }
            mark(color);
        }

        if(s == "shrink"){
            if(r > n || c > m || nr > n || nc > m){ bad(1); continue; }
            int color = grid[r][c];
            if(color == 0){ bad(2); continue; }
            auto [r1, c1, r2, c2] = get(color);
            if(r1 != r || c1 != c){ bad(3); continue; }
            int h1 = r2 - r1 + 1, w1 = c2 - c1 + 1;
            if(h1 < h || w1 < w){ bad(4); continue; }
            nr = r2; nc = c2;
            mark(0);
            nr = r + h - 1; nc = c + w - 1;
            mark(color);
        }
    }
    // print();

    set<int> ans;
    rep(i, 1, n + 1) rep(j, 1, m + 1) if(grid[i][j]) ans.insert(grid[i][j]);
    cout << sz(ans) << endl;
}