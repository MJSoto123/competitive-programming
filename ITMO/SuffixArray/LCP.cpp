#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)
#define dbg(a) cerr << (#a) << "\t"; for(auto x : a) cerr << x << " "; cerr << "\n";

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

void counting_sort(int n, vi &p, vi &c){
    vi cnt(n);
    rep(i, 0, n) cnt[c[i]]++;

    vi start(n);
    rep(i, 1, n) start[i] = start[i - 1] + cnt[i - 1];

    vi np(n);
    for(auto suf : p) np[start[c[suf]]++] = suf;
    p = np;
}

void suffix(string s, int n, vi &p, vi &c){
    {
        iota(all(p), 0);
        sort(all(p), [&](int l, int r){ return s[l] < s[r]; });
        rep(i, 1, n) c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
    }

    int k = log2(n) + 1;
    rep(exp, 0, k){
        vi np(n);
        rep(i, 0, n) np[i] = (p[i] - (1 << exp) + n) % n;
        counting_sort(n, np, c);
        p = np;

        vi nc(n);
        rep(i, 1, n){
            pii pre(c[p[i - 1]], c[(p[i - 1] + (1 << exp)) % n]);
            pii cur(c[p[i]], c[(p[i] + (1 << exp)) % n]);

            nc[p[i]] = nc[p[i - 1]] + (pre != cur);
        }
        c = nc;
    }
}

vi get_lcp(string s, int n, vi &p, vi &c){
    int k = 0;
    vi lcp(n, -1);
    for(int i = 0; i < n - 1; i++){
        int pi = p[c[i]];
        int pj = p[c[i] - 1];

        while(pi + k < n && pj + k < n && s[pi + k] == s[pj + k]) k++;
        lcp[c[i]] = k;
        k = max(0, k - 1);
    }
    return lcp;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    s += "$";
    
    int n = sz(s);
    vi p(n), c(n);
    suffix(s, n, p, c);
    vi lcp = get_lcp(s, n, p, c);

    rep(i, 0, n) cout << p[i] << " "; cout << "\n";
    rep(i, 1, n) cout << lcp[i] << " "; cout << "\n";
}