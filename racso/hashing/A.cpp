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

const int N = 6e5 + 100;
int pot[2][N];
int MOD[] = {1'000'000'000 + 7, 1'000'000'000 + 9};
int B[] = {257, 359};

int add(int a, int b, int m){ return (a + b >= m ? a + b - m : a + b); }
int sub(int a, int b, int m){ return (a - b >= 0 ? a - b : a + m - b); }
int mul(ll a, ll b, int m){ return (a * b) % m; }

void init(){
    rep(i, 0, 2){
        pot[i][0] = 1;
        rep(j, 1, N) pot[i][j] = mul(pot[i][j - 1], B[i], MOD[i]);
    }
}

pii get(int pos, char c){
    return make_pair(mul(pot[0][pos], c - 'a', MOD[0]), mul(pot[1][pos], c - 'a', MOD[1]));
}

pii H(const string &s){
    int n = sz(s);
    vi h(2);
    rep(i, 0, 2){
        rep(j, 0, n) h[i] = add(h[i], mul(s[j] - 'a', pot[i][j], MOD[i]), MOD[i]);
    }
    return make_pair(h[0], h[1]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();

    int n, m; cin >> n >> m;
    vector<set<pii>> st(N); 
    rep(i, 0, n){
        string s; cin >> s;
        st[sz(s)].insert(H(s));
    }

    rep(i, 0, m){
        string s; cin >> s;
        int k = sz(s);
        auto [h0, h1] = H(s);
        bool ok = false;
        rep(j, 0, k){
            auto [d0, d1] = get(j, s[j]);
            h0 = sub(h0, d0, MOD[0]);
            h1 = sub(h1, d1, MOD[1]);
                
            for(char c = 'a'; c <= 'c'; c++)if(s[j] != c){
                auto [val0, val1] = get(j, c);
                int tmp0 = add(h0, val0, MOD[0]);
                int tmp1 = add(h1, val1, MOD[1]);
                if(st[k].count({tmp0, tmp1})){ ok = true; break; }
            }
            h0 = add(h0, d0, MOD[0]);
            h1 = add(h1, d1, MOD[1]);
            if(ok) break;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}