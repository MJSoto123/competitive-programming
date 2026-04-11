#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

const ll inf = -2e18;
struct Node{
    ll sm[2][2];
    Node(){
        sm[0][0] = sm[0][1] = sm[1][0] = sm[1][1] = inf;
    }
    Node(int val){
        sm[0][0] = 0;
        sm[1][0] = sm[0][1] = inf;
        sm[1][1] = val;
    }
    Node operator+(const Node &other) const {
        Node ret;
        auto &xd = ret.sm;
        rep(l, 0, 2) rep(r, 0, 2){
            xd[l][r] = inf;
            rep(ml, 0, 2) rep(mr, 0, 2){
                if(ml && mr) continue;
                xd[l][r] = max(xd[l][r], sm[l][ml] + other.sm[mr][r]);
            }
        }

        return ret; 
    }
};

struct Seg{
    int n;
    vector<Node> t;
    void build(const vi &a, int v, int l, int r){
        if(l == r){
            t[v] = Node(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid + 1, r);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void init(const vi &a){
        n = sz(a);
        t.resize(4 * n + 10);
        build(a, 0, 0, n - 1);
    }

    void upd(int v, int l, int r, int pos, int val){
        if(pos < l || pos > r) return;
        if(l == r){
            t[v] = Node(val);
            return;
        }
        int mid = (l + r) >> 1;
        upd(2 * v + 1, l, mid, pos, val);
        upd(2 * v + 2, mid + 1, r, pos, val);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
    void upd(int pos, int val){ upd(0, 0, n - 1, pos, val); }
};

const int MOD = 1e9 + 7;
int add(ll a, ll b){ return (a + b) % MOD; }

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = sz(nums);
        Seg st;
        st.init(nums);

        int ret = 0;
        for(auto q : queries){
            int pos = q[0];
            int val = q[1];
            st.upd(pos, val);
            auto sm = st.t[0].sm;
            ll here = 0;
            rep(i, 0, 2) rep(j, 0, 2) here = max(here, sm[i][j]);
            ret = add(ret, here);
        }
        return ret;
    }
};