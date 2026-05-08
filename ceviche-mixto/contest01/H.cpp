#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int k, t; cin >> k >> t; 
    string s; cin >> s; 
    cerr << "[pot] " << (1 << k) << "\n"; 
    vvi to(31, vi(1 << k)); 
    { 
        int l = 0, r = (1 << (k - 1)), i = 0; 
        while(r < (1 << k)) { 
            to[0][i++] = l; 
            to[0][i++] = r; 
            l++, r++; 
        }
    }

    cerr << "first: "; 
    for(int i : to[0]) cerr << i << " "; cerr << "\n"; 

    rep(i,1,sz(to)) rep(j,0,(1 << k)) to[i][j] = to[i - 1][to[i - 1][j]]; 

    vi perm(1 << k); 
    rep(i,0,1<<k) { 
        int cur = i; 
        rep(bit,0,31) if((t >> bit) & 1) cur = to[bit][cur]; 
        perm[i] = cur;         
    }

    cerr << "final perm: " ; 
    for(int i : perm) cerr << i << " "; cerr << "\n"; 

    cerr << "string with perm: " ; 
    rep(i,0,1<<k) cerr << s[perm[i]]; 
    cerr << "\n"; 

    vector<string> vals; 
    rep(i,0,1<<k) { 
        string here; 
        for(int ind : perm) here.push_back(s[ind]); 
        rotate(s.begin(), s.begin() + 1, s.end()); 
        vals.push_back(here); 
    }
    
    cerr << "vals:\n"; 
    for(auto ss : vals) cerr << ss << "\n"; 

    int a = 0; 
    int siz = sz(perm); 
    rep(i,0,siz) perm.push_back(i); 
    rep(b,0,siz) rep(k,0,siz) { 
        if(perm[a + k] == perm[b] || s[perm[a + k]] < s[perm[b + k]]) { 
            b += max(0, k - 1); 
            break; 
        }
        if(s[perm[a + k]] > s[perm[b + k]]) { 
            a = b; 
            break;
        }
    }
    rotate(s.begin(), s.begin() + a, s.end()); 
    rep(i,0,siz) cout << s[perm[i]]; cout << "\n"; 
}