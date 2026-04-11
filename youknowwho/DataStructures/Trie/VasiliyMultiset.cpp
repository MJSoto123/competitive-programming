#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

const int MX = 30;
const int N = 200'005 * MX;
int t[N][2];
int cnt[N][2];

struct Trie{
    int id;
    Trie() : id(0) {}
    void insert(int val){
        int root = 0;
        for(int i = MX; i >= 0; i--){
            int bit = bool((1 << i) & val);
            if(cnt[root][bit] == 0){
                t[root][bit] = ++id;
            }
            cnt[root][bit]++;
            root = t[root][bit];
        }
    }

    void remove(int val){
        int root = 0;
        for(int i = MX; i >= 0; i--){
            int bit = bool((1 << i) & val);
            cnt[root][bit]--;
            int xd = t[root][bit];
            if(cnt[root][bit] == 0) t[root][bit] = 0;
            root = xd;
        }
    }

    void query(int val){
        int root = 0;
        int ans = 0;
        for(int i = MX; i >= 0; i--){
            int need = bool((1 << i) & val) ^ 1;
            if(cnt[root][need]){
                ans |= (1 << i);
                root = t[root][need];
            }
            else if(cnt[root][need ^ 1]) root = t[root][need ^ 1];
            else break;
        }
        cout << ans << "\n";
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q; cin >> q;
    Trie ds;
    ds.insert(0);
    rep(i, 0, q){
        char op; cin >> op;
        int val; cin >> val;
        if(op == '+') ds.insert(val);
        if(op == '-') ds.remove(val);
        if(op == '?') ds.query(val);
    }
}