#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll; 
typedef vector<ll> vl; 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pii> vii;



inline int add(int a, int b, const int &mod) { return a+b >= mod ? a+b-mod : a+b; }
inline int sbt(int a, int b, const int &mod) { return a-b < 0 ? a-b+mod : a-b; }
inline int mul(int a, int b, const int &mod) { return 1ll*a*b % mod; }

const int X[] = {257, 359}; // 31 43
const int MOD[] = {(int)1e9+7, (int)1e9+9};
const int N = 1e5 + 10;
int pows[N][2], ipows[N][2];
int h[2];

int binpow(int a, int exp, const int &mod) {
    int res = 1; 
    while(exp > 0) {
        if(exp % 2) res = mul(res, a, mod);
        a = mul(a, a, mod);
        exp >>= 1; 
    }
    return res; 
}

struct Hashing {
    string s;
    int n; 
    vvi ph; 

    Hashing(string &s) : s(s) { 
        n = s.size(); 
        ph.assign(n, vi(2));    
    }

    void build() {     
        for(int j = 0; j < 2; j++) {
            ph[0][j] = s[0];
            for(int i = 1; i < n; i++) {
                ph[i][j] = add(ph[i - 1][j], mul(pows[i][j], s[i], MOD[j]), MOD[j]);
            }
        }
    }

    pii substr_hash(int l, int r) {
        if(l == 0) return make_pair(ph[r][0], ph[r][1]);
        h[0] = mul(sbt(ph[r][0], ph[l - 1][0], MOD[0]), ipows[l][0], MOD[0]);
        h[1] = mul(sbt(ph[r][1], ph[l - 1][1], MOD[1]), ipows[l][1], MOD[1]);
        return make_pair(h[0], h[1]);
    }
};

void init() {
    for(int j = 0; j < 2; j++) {
        pows[0][j] = 1; 
        for(int i = 1; i < N; i++) pows[i][j] = mul(pows[i - 1][j], X[j], MOD[j]);
        ipows[N - 1][j] = binpow(pows[N - 1][j], MOD[j] - 2, MOD[j]);
        for(int i = N - 1; i > 0; i--) ipows[i - 1][j] = mul(ipows[i][j], X[j], MOD[j]);
    }
}

vi manacher_odd(string s) {
    int n = s.size();
    s = "@" + s + "$";
    vi len(n + 1);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        len[i] = min(r - i, len[l + (r - i)]);
        while(s[i - len[i]] == s[i + len[i]]) len[i]++;
        if(i + len[i] > r) {
            l = i - len[i];
            r = i + len[i];
        }
    }
    len.erase(begin(len));
    return len;
}

// para verificar si un substring es palindromo
// return pal[l + r] >= (r - l + 1) + 1; indexando en 0
vi manacher(string s) {
    string ns(1, '#'); 
    for(char c : s) {
        ns.push_back(c);
        ns.push_back('#');
    }
    auto res = manacher_odd(ns);
    return vi(res.begin() + 1, res.end() - 1);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    init(); 
    string s; cin >> s ; 
    Hashing hs(s); hs.build(); 
    vi man = manacher(s); 

    auto go = [&](bool even, int L, int R) -> pii { 
        // cerr << "check: " << (even ? "even " : "odd ") << "\n"; 
        int low = L, high = R; 
        // cerr << "low, high: " << low << " " << high << "\n"; 
        int beg = -1; 
        int n = sz(s); 
        while(high - low > 1) { 
            int mid = low + (high - low) / 2; 
            int len = (even ? 2 * mid : 2 * mid - 1); 
            // cerr << "mid: " << mid << "\n"; 
            // cerr << " len: " << len << "\n"; 
            if(len > n) { 
                high = mid; 
                continue; 
            } 
            map<pii, int> last_pos;
            int b = -1; 
            rep(i,0,n) { 
                if(i + len - 1 >= n) break; 
                int l = i, r = i + len - 1; 
                if(man[l + r] < r - l + 1 + 1) continue; 
                pii cur = hs.substr_hash(l, r); 
                if(last_pos.count(cur)) {
                    int last = last_pos[cur]; 
                    if(last < l) { 
                        b = l; 
                        break ; 
                    }
                }else last_pos[cur] = r; 
            }
            if(b != -1) low = mid, beg = b; 
            else high = mid; 
        }
        // cerr << "ret low,beg= " << low << " " << beg << "\n"; 
        return {low, beg}; 
    };

    auto ev = go(1,0,sz(s) / 2 + 2); 
    auto odd = go(0,0,sz(s) / 2 + 2); 

    // cerr << "ev: " << ev.first << " " << ev.second << "\n"; 
    // cerr << "odd: " << odd.first << " " << odd.second << "\n"; 

    int len_ev = (ev.second == -1 ? 0 : 2 * ev.first);
    int len_odd = (odd.second == -1 ? 0 : 2 * odd.first - 1); 
    if(len_ev == 0 && len_odd == 0) { 
        cout << "-1\n"; return 0; 
    }

    int beg = ev.second; 
    int len = len_ev; 
    if(len_ev < len_odd) { 
        beg = odd.second; 
        len = len_odd; 
    }  
    rep(i,0,len) cout << s[i + beg]; cout << "\n"; 
}
